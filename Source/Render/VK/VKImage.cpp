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

#include "VulkanImage.h"
#include "VulkanImageView.h"
#include "VulkanSampler.h"
#include "VulkanInline.h"
#include "VulkanDeviceMemory.h"
#include "VulkanCommandPool.h"
#include "VulkanCommandBuffer.h"
#include "VulkanDevice.h"
#include "VulkanQueue.h"

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
	assert(mImage == nullptr);
	mLayout = layout;
	VkFormat vk_format = ConvertFormat(mLayout.format);
	Context* context = StaticCast(mContext);
	Vulkan::Device* device = context->GetDeviceVK();

	VkExtent3D vk_extent = {};
	vk_extent.width = static_cast<uint32_t>(mLayout.extent.width);
	vk_extent.height = static_cast<uint32_t>(mLayout.extent.height);
	vk_extent.depth = static_cast<uint32_t>(mLayout.extent.depth);
	mImage = Vulkan::Image::New(device);
	mImage->Create(vk_format, vk_extent, Image::ConvertUsageFlag(mLayout.usage));
}

void Image::Create(Render::ImageType type, Render::Format format, const Render::Extent3& extent, uint32_t usage)
{
	mLayout.type = type;
	mLayout.format = format;
	mLayout.extent = extent;
	mLayout.usage.ImageUsageFlags = usage;

	assert(mImage == nullptr);
	VkFormat vk_format = ConvertFormat(format);
	Context* context = StaticCast(mContext);
	Vulkan::Device* device = context->GetDeviceVK();

	VkExtent3D vk_extent = {};
	vk_extent.width = static_cast<uint32_t>(extent.width);
	vk_extent.height = static_cast<uint32_t>(extent.height);
	vk_extent.depth = static_cast<uint32_t>(extent.depth);
	mImage = Vulkan::Image::New(device);
	mImage->Create(vk_format, vk_extent, Image::ConvertUsageFlag(mLayout.usage));
}

void Image::Allocate(Render::HeapAccess access)
{
	mAccess = access;
	assert(mImage != nullptr);
	auto flags = GetMemoryPropertyFlags(mAccess);
	Vulkan::Device* device = mImage->GetDevice();

	VkMemoryRequirements requirements = mImage->GetMemoryRequirements();
	mHeapSize = requirements.size;

	mMemory = Vulkan::DeviceMemory::New(device);
	mMemory->Allocate(requirements, flags);
	mImage->BindMemory(mMemory, 0);
}

void Image::CreateView(Render::ImageType type)
{
	assert(mLayout.type == type);
	assert(mLayout.type != Render::ImageType::IMAGE_TYPE_UNKNOWN);
	assert(mMemory != nullptr);
	VkImageViewType vk_type = ConverType(mLayout.type);
	mImage->CreateView(vk_type);
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
	Context* context = StaticCast(mContext);
	Vulkan::CommandPool* command_pool = context->GetCommandPoolVK();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	VkBufferImageCopy copy_region = {};
	copy_region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	copy_region.imageSubresource.layerCount = 1;
	copy_region.imageExtent.width = mLayout.extent.width;
	copy_region.imageExtent.height = mLayout.extent.height;
	copy_region.imageExtent.depth = mLayout.extent.depth;

	const Buffer* buffer = static_cast<const Buffer*>(other);
	Vulkan::Buffer* vk_buffer = buffer->GetBufferVK();

	command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
	command_buffer->CopyResource(vk_buffer, mImage, 1, &copy_region);
	command_buffer->End();

	Vulkan::Device* device = context->GetDeviceVK();
	Vulkan::Queue* queue = device->GetQueue(command_pool->GetFamily(), 0);
	queue->FlushCommandBuffer(command_buffer);
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

VkImageUsageFlags Image::ConvertUsageFlag(Render::ImageUsage usage)
{
	VkImageUsageFlags flags = 0;
	if (usage.ImageUsageCommon == 1)
	{
		flags |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
		flags |= VK_IMAGE_USAGE_TRANSFER_DST_BIT;
	}
	if (usage.ImageUsageSampled == 1)
	{
		flags |= VK_IMAGE_USAGE_SAMPLED_BIT;
	}
	if (usage.ImageUsageStorage == 1)
	{
		flags |= VK_IMAGE_USAGE_STORAGE_BIT;
	}
	if (usage.ImageUsageColorAttachment == 1)
	{
		flags |= VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
	}
	if (usage.ImageUsageDepthStencilAttachment == 1)
	{
		flags |= VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;
	}
	if (usage.ImageUsageTransientAttachment == 1)
	{
		flags |= VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT;
	}
	if (usage.ImageUsageInputAttachment == 1)
	{
		flags |= VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT;
	}
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
