/*
 * VKImage.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKImage.h"
#include "VKFormat.h"
#include "VKBuffer.h"
#include "VKInline.h"
#include "VKFactory.h"
#include "VKPool.h"
#include "VKOperator.h"
#include "VKDevice.h"

#include "../../Core/Kernel/KernelAlignment.h"
#include "../../Platform/Vulkan/VulkanImage.h"
#include "../../Platform/Vulkan/VulkanImageView.h"
#include "../../Platform/Vulkan/VulkanSampler.h"
#include "../../Platform/Vulkan/VulkanInline.h"
#include "../../Platform/Vulkan/VulkanDeviceMemory.h"
#include "../../Platform/Vulkan/VulkanCommandPool.h"
#include "../../Platform/Vulkan/VulkanCommandBuffer.h"
#include "../../Platform/Vulkan/VulkanDevice.h"
#include "../../Platform/Vulkan/VulkanQueue.h"

#include <cstring>
#include <iostream>

namespace VK
{

Image::Image(Device* device):
		GHI::Image(device)
{
}

Image::~Image(void)
{
	Vulkan::Release(mImage);
	Vulkan::Release(mMemory);
}

void Image::Create(const GHI::ImageLayout& layout, const GHI::UsageType& usage)
{
	mUsage = usage;
	mLayout = layout;
	CreateImage();
	AllocateMemory();
	CreateView();
}

void Image::CreateImage(void)
{
	assert(mImage == nullptr);
	GHI::Format format = mLayout.GetFormat();
	VkFormat vulkan_format = ConvertFormat(format);
	Device* vk_device = static_cast<Device*>(mDevice);
	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	const Math::Extent3Di& extent = mLayout.GetExtent();
	VkExtent3D vulkan_extent =
	{
		static_cast<uint32_t>(extent.width),
		static_cast<uint32_t>(extent.height),
		static_cast<uint32_t>(extent.depth)
	};

	VkImageUsageFlags usage = Image::ConvertUsageFlag(mUsage);
	mImage = Vulkan::Image::New(vulkan_device);
	mImage->Create(vulkan_format, vulkan_extent, usage);
}

void Image::AllocateMemory(void)
{
	assert(mImage != nullptr);
	auto flags = GetMemoryPropertyFlags(mUsage);
	Vulkan::Device* device = mImage->GetDevice();

	auto& requirements = mImage->GetMemoryRequirements();
	mHeapSize = requirements.size;

	mMemory = Vulkan::DeviceMemory::New(device);
	mMemory->Allocate(requirements, flags);
	mImage->BindMemory(mMemory, 0);
}

void Image::CreateView(void)
{
	GHI::ImageType type = mLayout.GetType();
	assert(type != GHI::ImageType::IMAGE_TYPE_UNKNOWN);
	assert(mMemory != nullptr);
	VkImageViewType vulkan_type = ConverType(type);
	mImage->CreateView(vulkan_type);
}

void* Image::Map(size_t offset, size_t size)
{
	assert(false);
	return nullptr;
}
void Image::Unmap(size_t offset, size_t size)
{
	assert(false);
}

void Image::Download(void* dst)
{
	assert(false);
}

void Image::Upload(uint32_t index, uint32_t mipmap, const void* src)
{
	assert(index == 0 && mipmap == 0);
	GHI::Factory* factory = mDevice->GetFactory();
	Factory* vk_factory = static_cast<Factory*>(factory);
	Pool* vk_pool = vk_factory->GetPool();
	Vulkan::CommandPool* command_pool = vk_pool->GetVulkanCommandPool();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	size_t buffer_size = GetMipmapSize(mipmap);
	Buffer* stage_buffer = vk_pool->GetStageBuffer(buffer_size);
	void* dst = stage_buffer->Map(0, buffer_size);
	std::memcpy(dst, src, buffer_size);
	stage_buffer->Unmap(0, buffer_size);

	VkExtent2D extent = GetMipmapExtent(mipmap);

	VkBufferImageCopy copy_region = {};
	copy_region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	copy_region.imageSubresource.mipLevel = 0;
	copy_region.imageSubresource.baseArrayLayer = mipmap;
	copy_region.imageSubresource.layerCount = 1;
	copy_region.imageExtent = { extent.width, extent.height, 1 };
	copy_region.bufferOffset = 0;

	auto vulkan_buffer = stage_buffer->GetVulkanBuffer();

	command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
	command_buffer->CopyResource(vulkan_buffer, mImage, 1, &copy_region);
	command_buffer->End();

	auto vk_device = static_cast<Device*>(mDevice);
	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	uint32_t queue_family = command_pool->GetFamily();
	Vulkan::Queue* queue = vulkan_device->GetQueue(queue_family, 0);
	queue->FlushCommandBuffer(command_buffer);
}

VkClearValue Image::GetClearValue(void) const
{
	VkClearValue clear_value = {};
	bool depth_stencil = mImage->IsDepthStencil();
	if(depth_stencil)
	{
		clear_value.depthStencil.depth = 1.0f;
		clear_value.depthStencil.stencil = 0;
	}
	else
	{
		Math::Color clear_color = mLayout.GetClearColor();
		clear_value.color.float32[0] = clear_color.GetRed();
		clear_value.color.float32[1] = clear_color.GetGreen();
		clear_value.color.float32[2] = clear_color.GetBlue();
		clear_value.color.float32[3] = clear_color.GetAlpha();
	}
	return clear_value;
}

VkDescriptorImageInfo Image::GetDescriptorInfo(void) const
{
	assert(mImage != nullptr);
	assert(mMemory != nullptr);
	auto view = mImage->GetView();
	assert(view != nullptr);
	VkDescriptorImageInfo descriptor_info = {};
	descriptor_info.imageView = mImage->GetView()->GetHandle();
	descriptor_info.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
	return descriptor_info;
}

void Image::CopyFrom(const GHI::Resource* other)
{
	Device* vk_device = static_cast<Device*>(mDevice);
	GHI::Factory* factory = mDevice->GetFactory();
	Factory* vk_factory = static_cast<Factory*>(factory);
	Pool* vk_pool = vk_factory->GetPool();
	auto command_pool = vk_pool->GetVulkanCommandPool();
	auto command_buffer = command_pool->GetCommandBuffer(0);

	GHI::ResourceType type = other->GetType();
	if (type == GHI::ResourceType::BUFFER)
	{
		const Buffer* vk_buffer = static_cast<const Buffer*>(other);
		Vulkan::Buffer* vulkan_buffer = vk_buffer->GetVulkanBuffer();
		const Math::Extent3Di& extent = mLayout.GetExtent();
		VkBufferImageCopy copy_region = {};
		copy_region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		copy_region.imageSubresource.layerCount = 1;
		copy_region.imageExtent.width = extent.width;
		copy_region.imageExtent.height = extent.height;
		copy_region.imageExtent.depth = extent.depth;

		command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
		command_buffer->CopyResource(vulkan_buffer, mImage, 1, &copy_region);
		command_buffer->End();
	}

	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	uint32_t queue_family = command_pool->GetFamily();
	Vulkan::Queue* queue = vulkan_device->GetQueue(queue_family, 0);
	queue->FlushCommandBuffer(command_buffer);
}

size_t Image::GetMipmapSize(uint32_t mipmap) const
{
	GHI::Format format = mLayout.GetFormat();
	size_t format_size = GetFormatSize(format);
	VkExtent2D extent = GetMipmapExtent(mipmap);
	size_t size_in_byte = extent.width * extent.height * format_size;
	return size_in_byte;
}

VkExtent2D Image::GetMipmapExtent(uint32_t mipmap) const
{
	const auto& extent = mLayout.GetExtent();
	if (mipmap > 0)
	{
		bool width_pow2 = Kernel::IsPowerOfTow(extent.width);
		bool height_pow2 = Kernel::IsPowerOfTow(extent.height);
		assert(width_pow2 == true);
		assert(height_pow2 == true);
		if (!width_pow2 || !height_pow2)
		{
			std::cout << extent.width << " " << extent.height << std::endl;
			std::cout << "Width and Height must Power of 2 !" << std::endl;
		}
	}

	VkExtent2D vk_extent =
	{
		extent.width / (1u << mipmap),
		extent.height / (1u << mipmap)
	};
	return vk_extent;
}

VkDescriptorType Image::GetDescriptorType(const GHI::UsageType& usage)
{
	VkDescriptorType descriptor_type =
	(usage.sampledImage == 1) ? VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE :
	(usage.storageImage == 1) ? VK_DESCRIPTOR_TYPE_STORAGE_IMAGE :
	(usage.inputImage == 1) ? VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT :
			VK_DESCRIPTOR_TYPE_MAX_ENUM;
	assert(descriptor_type != VK_DESCRIPTOR_TYPE_MAX_ENUM);
	return descriptor_type;
}

VkImageViewType Image::ConverType(const GHI::ImageType& type)
{
	switch (type)
	{
	case GHI::ImageType::IMAGE_TYPE_1D:
		return VK_IMAGE_VIEW_TYPE_1D;
	case GHI::ImageType::IMAGE_TYPE_2D:
		return VK_IMAGE_VIEW_TYPE_2D;
	case GHI::ImageType::IMAGE_TYPE_3D:
		return VK_IMAGE_VIEW_TYPE_3D;
	case GHI::ImageType::IMAGE_TYPE_CUBE:
		return VK_IMAGE_VIEW_TYPE_CUBE;
	case GHI::ImageType::IMAGE_TYPE_1D_ARRAY:
		return VK_IMAGE_VIEW_TYPE_1D_ARRAY;
	case GHI::ImageType::IMAGE_TYPE_2D_ARRAY:
		return VK_IMAGE_VIEW_TYPE_2D_ARRAY;
	case GHI::ImageType::IMAGE_TYPE_CUBE_ARRAY:
		return VK_IMAGE_VIEW_TYPE_CUBE_ARRAY;
	default:
		assert(false);
		return VK_IMAGE_VIEW_TYPE_MAX_ENUM;
	}
}

GHI::ImageType Image::ConverType(const VkImageViewType& type)
{
	switch (type)
	{
	case VK_IMAGE_VIEW_TYPE_1D:
		return GHI::ImageType::IMAGE_TYPE_1D;
	case VK_IMAGE_VIEW_TYPE_2D:
		return GHI::ImageType::IMAGE_TYPE_2D;
	case VK_IMAGE_VIEW_TYPE_3D:
		return GHI::ImageType::IMAGE_TYPE_3D;
	case VK_IMAGE_VIEW_TYPE_CUBE:
		return GHI::ImageType::IMAGE_TYPE_CUBE;
	case VK_IMAGE_VIEW_TYPE_1D_ARRAY:
		return GHI::ImageType::IMAGE_TYPE_1D_ARRAY;
	case VK_IMAGE_VIEW_TYPE_2D_ARRAY:
		return GHI::ImageType::IMAGE_TYPE_2D_ARRAY;
	case VK_IMAGE_VIEW_TYPE_CUBE_ARRAY:
		return GHI::ImageType::IMAGE_TYPE_CUBE_ARRAY;
	default:
		assert(false);
		return GHI::ImageType::IMAGE_TYPE_UNKNOWN;
	}
}

VkImageUsageFlags Image::ConvertUsageFlag(GHI::UsageType usage)
{
	assert(usage.type == GHI::ResourceType::IMAGE);
	VkImageUsageFlags flags = 0;
	flags |= (usage.read == TRUE) ? VK_IMAGE_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (usage.write == TRUE) ? VK_IMAGE_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (usage.sampledImage == TRUE) ? VK_IMAGE_USAGE_SAMPLED_BIT : 0;
	flags |= (usage.storageImage == TRUE) ? VK_IMAGE_USAGE_STORAGE_BIT : 0;
	flags |= (usage.colorImage == TRUE) ? VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT : 0;
	flags |= (usage.depthStencil == TRUE) ? VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT : 0;
	flags |= (usage.transientImage == TRUE) ? VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT : 0;
	flags |= (usage.inputImage == TRUE) ? VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT : 0;
	return flags;
}

SwapChainImage::SwapChainImage(Device* device):
		Image(device)
{
}

SwapChainImage::~SwapChainImage(void)
{
	mImage = nullptr;
	mMemory = nullptr;
}

void SwapChainImage::Create(Vulkan::Image* image)
{
	assert(image != nullptr);
	mImage = image;
	VkExtent2D vk_extent = image->GetExtent();
	Math::Extent3Di extent = {};
	extent.width = static_cast<int32_t>(vk_extent.width);
	extent.height = static_cast<int32_t>(vk_extent.height);
	extent.depth = 1;
	mLayout.SetExtent(extent);
	VkFormat vk_format = image->GetFormat();
	GHI::Format format = ConvertFormat(vk_format);
	mLayout.SetFormat(format);
	mLayout.SetType(GHI::ImageType::IMAGE_TYPE_2D);
}

} /* namespace VK */
