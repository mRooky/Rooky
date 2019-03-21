/*
 * VKImage.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKImage.h"
#include "VKContext.h"
#include "VKFormat.h"
#include "VKBuffer.h"
#include "VKInline.h"
#include "VKFactory.h"
#include "VKResourceHeap.h"
#include "VKOperator.h"

#include "VulkanImage.h"
#include "VulkanImageView.h"
#include "VulkanSampler.h"
#include "VulkanInline.h"
#include "VulkanDeviceMemory.h"
#include "VulkanCommandPool.h"
#include "VulkanCommandBuffer.h"
#include "VulkanDevice.h"
#include "VulkanQueue.h"

#include "MathBits.hpp"

#include <cstring>
#include <iostream>

namespace VK
{

Image::Image(Context* context):
		Render::Image(context)
{
}

Image::~Image(void)
{
	Vulkan::Release(mImage);
	Vulkan::Release(mMemory);
}

void Image::Create(const Render::ImageLayout& layout)
{
	mLayout = layout;
	CreateImage();
	AllocateMemory();
	CreateView();
}

void Image::CreateImage(void)
{
	assert(mImage == nullptr);
	VkFormat vulkan_format = ConvertFormat(mLayout.format);
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetVulkanDevice();

	VkExtent3D vulkan_extent = {};
	vulkan_extent.width = static_cast<uint32_t>(mLayout.extent.width);
	vulkan_extent.height = static_cast<uint32_t>(mLayout.extent.height);
	vulkan_extent.depth = static_cast<uint32_t>(mLayout.extent.depth);

	VkImageUsageFlags usage = Image::ConvertUsageFlag(mLayout.usage);
	mImage = Vulkan::Image::New(device);
	mImage->Create(vulkan_format, vulkan_extent, usage);
}

void Image::AllocateMemory(void)
{
	assert(mImage != nullptr);
	auto flags = GetMemoryPropertyFlags(mLayout.usage.allocate);
	Vulkan::Device* device = mImage->GetDevice();

	auto& requirements = mImage->GetMemoryRequirements();
	mHeapSize = requirements.size;

	mMemory = Vulkan::DeviceMemory::New(device);
	mMemory->Allocate(requirements, flags);
	mImage->BindMemory(mMemory, 0);
}

void Image::CreateView(void)
{
	assert(mLayout.type != Render::ImageType::IMAGE_TYPE_UNKNOWN);
	assert(mMemory != nullptr);
	VkImageViewType vulkan_type = ConverType(mLayout.type);
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

}

void Image::Upload(uint32_t index, uint32_t mipmap, const void* src)
{
	assert(index == 0 && mipmap == 0);
	Factory* factory = static_cast<Factory*>(mContext->GetFactory());
	Vulkan::CommandPool* command_pool = factory->GetVulkanCommandPool();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	size_t buffer_size = GetMipmapSize(mipmap);
	auto resource_heap = factory->GetResourceHeap();
	VkBufferUsageFlags usage = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
	auto stage_buffer = resource_heap->AcquireBuffer(buffer_size, usage, true);
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

	command_buffer->CopyResource(vulkan_buffer, mImage, 1, &copy_region);
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
		clear_value.color.float32[0] = mClearColor.GetRed();
		clear_value.color.float32[1] = mClearColor.GetGreen();
		clear_value.color.float32[2] = mClearColor.GetBlue();
		clear_value.color.float32[3] = mClearColor.GetAlpha();
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

void Image::CopyFrom(const Render::Buffer* other)
{
	Context* context = static_cast<Context*>(mContext);
	Factory* factory = static_cast<Factory*>(mContext->GetFactory());
	auto command_pool = factory->GetVulkanCommandPool();
	auto command_buffer = command_pool->GetCommandBuffer(0);

	VkBufferImageCopy copy_region = {};
	copy_region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	copy_region.imageSubresource.layerCount = 1;
	copy_region.imageExtent.width = mLayout.extent.width;
	copy_region.imageExtent.height = mLayout.extent.height;
	copy_region.imageExtent.depth = mLayout.extent.depth;

	const Buffer* buffer = static_cast<const Buffer*>(other);
	Vulkan::Buffer* vulkan_buffer = buffer->GetVulkanBuffer();

	command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
	command_buffer->CopyResource(vulkan_buffer, mImage, 1, &copy_region);
	command_buffer->End();

	Vulkan::Device* device = context->GetVulkanDevice();
	uint32_t queue_family = command_pool->GetFamily();
	Vulkan::Queue* queue = device->GetQueue(queue_family, 0);
	queue->FlushCommandBuffer(command_buffer);
}

size_t Image::GetMipmapSize(uint32_t mipmap) const
{
	size_t format_size = GetFormatSize(mLayout.format);
	VkExtent2D extent = GetMipmapExtent(mipmap);
	size_t size_in_byte = extent.width * extent.height * format_size;
	return size_in_byte;
}

VkExtent2D Image::GetMipmapExtent(uint32_t mipmap) const
{
	VkExtent2D extent = {};
	if (mipmap > 0)
	{
		const auto& extent = mLayout.extent;
		bool width_pow2 = Render::IsPowerOfTow(extent.width);
		bool height_pow2 = Render::IsPowerOfTow(extent.height);
		assert(width_pow2 == true);
		assert(height_pow2 == true);
		if (!width_pow2 || !height_pow2)
		{
			std::cout << extent.width << " " << extent.height << std::endl;
			std::cout << "Width and Height must Power of 2 !" << std::endl;
		}
	}
	extent.width = mLayout.extent.width / (1u << mipmap);
	extent.height = mLayout.extent.height / (1u << mipmap);
	return extent;
}

VkImageViewType Image::ConverType(const Render::ImageType& type)
{
	switch (type)
	{
	case Render::ImageType::IMAGE_TYPE_1D:
		return VK_IMAGE_VIEW_TYPE_1D;
	case Render::ImageType::IMAGE_TYPE_2D:
		return VK_IMAGE_VIEW_TYPE_2D;
	case Render::ImageType::IMAGE_TYPE_3D:
		return VK_IMAGE_VIEW_TYPE_3D;
	case Render::ImageType::IMAGE_TYPE_CUBE:
		return VK_IMAGE_VIEW_TYPE_CUBE;
	case Render::ImageType::IMAGE_TYPE_1D_ARRAY:
		return VK_IMAGE_VIEW_TYPE_1D_ARRAY;
	case Render::ImageType::IMAGE_TYPE_2D_ARRAY:
		return VK_IMAGE_VIEW_TYPE_2D_ARRAY;
	case Render::ImageType::IMAGE_TYPE_CUBE_ARRAY:
		return VK_IMAGE_VIEW_TYPE_CUBE_ARRAY;
	default:
		assert(false);
		return VK_IMAGE_VIEW_TYPE_MAX_ENUM;
	}
}

Render::ImageType Image::ConverType(const VkImageViewType& type)
{
	switch (type)
	{
	case VK_IMAGE_VIEW_TYPE_1D:
		return Render::ImageType::IMAGE_TYPE_1D;
	case VK_IMAGE_VIEW_TYPE_2D:
		return Render::ImageType::IMAGE_TYPE_2D;
	case VK_IMAGE_VIEW_TYPE_3D:
		return Render::ImageType::IMAGE_TYPE_3D;
	case VK_IMAGE_VIEW_TYPE_CUBE:
		return Render::ImageType::IMAGE_TYPE_CUBE;
	case VK_IMAGE_VIEW_TYPE_1D_ARRAY:
		return Render::ImageType::IMAGE_TYPE_1D_ARRAY;
	case VK_IMAGE_VIEW_TYPE_2D_ARRAY:
		return Render::ImageType::IMAGE_TYPE_2D_ARRAY;
	case VK_IMAGE_VIEW_TYPE_CUBE_ARRAY:
		return Render::ImageType::IMAGE_TYPE_CUBE_ARRAY;
	default:
		assert(false);
		return Render::ImageType::IMAGE_TYPE_UNKNOWN;
	}
}

VkImageUsageFlags Image::ConvertUsageFlag(Render::ResourceUsage usage)
{
	assert(usage.type == Render::ResourceType::RESOURCE_TYPE_IMAGE);
	VkImageUsageFlags flags = 0;
	flags |= (usage.allocate.Source == 1) ? VK_IMAGE_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (usage.allocate.Destination == 1) ? VK_IMAGE_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (usage.imageUsage.SampledImage == 1) ? VK_IMAGE_USAGE_SAMPLED_BIT : 0;
	flags |= (usage.imageUsage.StorageImage == 1) ? VK_IMAGE_USAGE_STORAGE_BIT : 0;
	flags |= (usage.imageUsage.ColorImage == 1) ? VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT : 0;
	flags |= (usage.imageUsage.DepthStencil == 1) ? VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT : 0;
	flags |= (usage.imageUsage.TransientImage == 1) ? VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT : 0;
	flags |= (usage.imageUsage.InputImage == 1) ? VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT : 0;
	return flags;
}

SwapChainImage::SwapChainImage(Context* context):
		Image(context)
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
	VkExtent2D extent = image->GetExtent();
	mLayout.extent.width = static_cast<int32_t>(extent.width);
	mLayout.extent.height = static_cast<int32_t>(extent.height);
	VkFormat format = image->GetFormat();
	mLayout.format = ConvertFormat(format);
	mLayout.type = Render::ImageType::IMAGE_TYPE_2D;
}

} /* namespace VK */
