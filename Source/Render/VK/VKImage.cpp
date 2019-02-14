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

void Image::Create(Render::Format format, const Render::Extent3& extent, uint32_t usage)
{
	assert(mImage == nullptr);

	mFormat = format;
	mExtent = extent;
	mUsage = usage;

	VkFormat vk_format = ConvertFormat(format);
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetDeviceVK();
	mImage = Vulkan::Image::New(device);
	mImage->Create(vk_format, mExtent.width, mExtent.height, mExtent.depth, usage);
}

void Image::Allocate(bool mappable)
{
	assert(mImage != nullptr);
	auto flags = GetMemoryPropertyFlags(mappable);
	Vulkan::Device* device = mImage->GetDevice();
	mMemory = Vulkan::DeviceMemory::New(device);
	mMemory->Allocate(mImage, flags);
	mImage->BindMemory(mMemory, 0);
}

void Image::CreateView(Render::ImageType type)
{
	mType = type;
	assert(mMemory != nullptr);
	VkImageViewType vk_type = ConverType(type);
	mImage->CreateView(vk_type);
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

void* Image::Map(size_t offset, size_t size)
{
	assert(mMemory != nullptr);
	return mMemory->Map(offset, size);
}

void Image::Unmap(size_t offset, size_t size)
{
	assert(mMemory != nullptr);
	mMemory->Unmap();
	mMemory->Flush(offset, size);
}

void Image::CopyFrom(const Render::Buffer* other)
{
	Context* context = static_cast<Context*>(mContext);
	Vulkan::CommandPool* command_pool = context->GetCommandPoolVK();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	VkBufferImageCopy copy_region = {};
	copy_region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	copy_region.imageSubresource.layerCount = 1;
	copy_region.imageExtent.width = mExtent.width;
	copy_region.imageExtent.height = mExtent.height;
	copy_region.imageExtent.depth = mExtent.depth;

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

VkImageUsageFlags Image::ConvertUsageFlag(uint32_t usage)
{
	VkImageUsageFlags flags = 0;
	Render::ImageUsageFlags usage_flags[] =
	{
			Render::ImageUsageFlags::IMAGE_USAGE_SAMPLED,
			Render::ImageUsageFlags::IMAGE_USAGE_STORAGE,
			Render::ImageUsageFlags::IMAGE_USAGE_COLOR_ATTACHMENT,
			Render::ImageUsageFlags::IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT,
			Render::ImageUsageFlags::IMAGE_USAGE_TRANSIENT_ATTACHMENT,
			Render::ImageUsageFlags::IMAGE_USAGE_INPUT_ATTACHMENT
	};

	VkImageUsageFlags vk_flags[] =
	{
			VK_IMAGE_USAGE_SAMPLED_BIT,
			VK_IMAGE_USAGE_STORAGE_BIT,
			VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
			VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
			VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT,
			VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT
	};

	const size_t count = 6;
	for (size_t index = 0; index < count; ++index)
	{
		auto flag = usage_flags[index];
		uint32_t code = static_cast<uint32_t>(flag);
		if ((usage & code) != 0)
		{
			flags |= vk_flags[index];
		}
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
	mExtent.width = static_cast<int32_t>(extent.width);
	mExtent.height = static_cast<int32_t>(extent.height);
	VkFormat format = image->GetFormat();
	mFormat = ConvertFormat(format);
	mType = Render::ImageType::IMAGE_TYPE_2D;
}

} /* namespace VK */
