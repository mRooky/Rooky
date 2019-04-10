/*
 * VulkanImage.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanImage.h"
#include "VulkanDevice.h"
#include "VulkanBuffer.h"
#include "VulkanDeviceMemory.h"
#include "VulkanImageView.h"
#include "VulkanCommandBuffer.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanInline.h"
#include <cassert>

namespace Vulkan
{

Image::Image(Device* device):
		Resource(device)
{
}

Image::~Image(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyImage(device, mImage, nullptr);
	mImage = VK_NULL_HANDLE;
	Release(m_view);
}

VkResult Image::Create(const VkImageCreateInfo* info)
{
	assert(mImage == VK_NULL_HANDLE);
	mResult = vkCreateImage(mDevice->GetHandle(), info, nullptr, &mImage);
	assert(mResult == VK_SUCCESS);
	mInfo = *info;
	vkGetImageMemoryRequirements(mDevice->GetHandle(), mImage, &mRequirement);
	return mResult;
}

VkResult Image::Create(VkFormat format, const VkExtent3D& extent, VkImageUsageFlags usage)
{
	const uint32_t mipmap = 1;
	const uint32_t array = 1;
	return Create(format, extent, mipmap, array, usage);
}

VkResult Image::Create(VkFormat format, uint32_t width, uint32_t height, uint32_t depth, VkImageUsageFlags usage)
{
	VkExtent3D extent = { width, height, depth};
	return Create(format, extent, usage);
}

VkResult Image::Create(VkFormat format, const VkExtent3D& extent, uint32_t mipmap, uint32_t array, VkImageUsageFlags usage)
{
	PhysicalDevice* physical = mDevice->GetPhysicalDevice();
	uint32_t family = physical->GetFamily();
	VkImageTiling tiling = physical->GetFormatTiling(format, VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT);

	VkImageCreateInfo image_create_info = Vulkan::Image::CreateInfo();
	image_create_info.format = format;
	image_create_info.extent = extent;
	image_create_info.mipLevels = mipmap;
	image_create_info.arrayLayers = array;
	image_create_info.usage = usage;
	image_create_info.tiling = tiling;
	image_create_info.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	image_create_info.queueFamilyIndexCount = 1;
	image_create_info.pQueueFamilyIndices = &family;
	return Create(&image_create_info);
}

VkResult Image::CreateView(VkImageViewType type)
{
	assert(m_view == nullptr);
	m_view = ImageView::New(mDevice);
	VkImageSubresourceRange sub_resource_range = {};
	sub_resource_range.aspectMask = ImageView::GetAspectFlags(mInfo.format);
	sub_resource_range.layerCount = mInfo.arrayLayers;
	sub_resource_range.levelCount = mInfo.mipLevels;
	return m_view->Create(this, type, sub_resource_range);
}

bool Image::IsDepthStencil(void) const
{
	VkFormat format = mInfo.format;
	return Vulkan::ImageView::IsDepthFormat(format);
}

VkClearValue Image::GetClearValue(void) const
{
	VkClearValue clear_value = {};
	VkFormat format = mInfo.format;
	if(Vulkan::ImageView::IsDepthFormat(format))
	{
		clear_value.depthStencil.depth = 1.0f;
		clear_value.depthStencil.stencil = 0;
	}
	else
	{
		clear_value.color.float32[0] = 220.0f / 255.0f;;
		clear_value.color.float32[1] = 127.0f / 255.0f;
		clear_value.color.float32[2] = 255.0f / 255.0f;;
		clear_value.color.float32[3] = 1.0f;
	}
	return clear_value;
}

VkResult Image::BindMemory(DeviceMemory* memory, VkDeviceSize offset)
{
	mMemory = memory;
	mOffset = offset;
	VkDevice device = mDevice->GetHandle();
	VkDeviceMemory handle = memory->GetHandle();
	VkResult result = vkBindImageMemory(device, mImage, handle, offset);
	assert(result == VK_SUCCESS);
	return result;
}

VkImageLayout Image::SetLayout(CommandBuffer* command, VkImageLayout layout)
{
	VkImageMemoryBarrier image_memory_barrier = GetMemoryBarrier();
	image_memory_barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
	image_memory_barrier.newLayout = layout;
	image_memory_barrier.image = mImage;
	image_memory_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	image_memory_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	image_memory_barrier.dstAccessMask = Image::GetAccessFlags(layout);

//	VkPipelineStageFlags flags = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
	VkPipelineStageFlags flags = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT;
//	VkPipelineStageFlags src_stages = Image::GetStageFlags(image_memory_barrier.oldLayout);
//	VkPipelineStageFlags dst_stages = Image::GetStageFlags(layout);

	VkCommandBuffer command_buffer = command->GetHandle();
	vkCmdPipelineBarrier(command_buffer, flags, flags, 0, 0, nullptr, 0, nullptr, 1, &image_memory_barrier);

	mInfo.initialLayout = layout;
	return image_memory_barrier.oldLayout;
}

void Image::ClearValue(CommandBuffer* command, VkClearValue value, uint32_t count, const VkImageSubresourceRange* ranges)
{

	assert(false);
}

VkAttachmentDescription Image::GetDescription(VkFormat format)
{
	bool depth = ImageView::IsDepthFormat(format);

	VkAttachmentDescription attachment_description = {};
	attachment_description.format = format;
	attachment_description.samples = VK_SAMPLE_COUNT_1_BIT;
	attachment_description.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
	attachment_description.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
	attachment_description.stencilLoadOp = depth ? VK_ATTACHMENT_LOAD_OP_CLEAR : VK_ATTACHMENT_LOAD_OP_DONT_CARE;
	attachment_description.stencilStoreOp = depth ? VK_ATTACHMENT_STORE_OP_STORE : VK_ATTACHMENT_STORE_OP_DONT_CARE;
	attachment_description.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	attachment_description.finalLayout = depth ? VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL : VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

	return attachment_description;
}

VkExtent2D Image::GetExtent(void) const
{
	VkExtent2D extent = {};
	extent.width = mInfo.extent.width;
	extent.height = mInfo.extent.height;
	return extent;
}

VkDescriptorImageInfo Image::GetDescriptorInfo(void) const
{
	VkDescriptorImageInfo descriptor_image_info = {};
	descriptor_image_info.imageView = m_view->GetHandle();
	descriptor_image_info.imageLayout = mInfo.initialLayout;
	return descriptor_image_info;
}

VkImageMemoryBarrier Image::GetMemoryBarrier(void) const
{
	assert(mMemory != nullptr);;
	VkImageMemoryBarrier image_memory_barrier = Image::MemoryBarrier();
	image_memory_barrier.image = mImage;
	image_memory_barrier.oldLayout = mInfo.initialLayout;
	image_memory_barrier.srcAccessMask = Image::GetAccessFlags(mInfo.initialLayout);
	image_memory_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	image_memory_barrier.subresourceRange.layerCount = mInfo.arrayLayers;
	image_memory_barrier.subresourceRange.levelCount = mInfo.mipLevels;
	image_memory_barrier.subresourceRange.baseMipLevel = 0;
	image_memory_barrier.subresourceRange.baseArrayLayer = 0;
	return image_memory_barrier;
}
VkAttachmentReference Image::GetReference(VkFormat format)
{
	VkAttachmentReference reference = {};
	bool depth = ImageView::IsDepthFormat(format);
	reference.layout = depth ? VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL : VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
	return reference;
}

VkImageMemoryBarrier Image::MemoryBarrier(void)
{
	VkImageMemoryBarrier image_memory_barrier = {};
	image_memory_barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
	image_memory_barrier.pNext = nullptr;
	image_memory_barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	image_memory_barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
	return image_memory_barrier;
}

VkAccessFlags Image::GetAccessFlags(VkImageLayout layout)
{
	VkAccessFlags flags = 0;
	switch (layout)
	{
	case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
		flags = VK_ACCESS_TRANSFER_READ_BIT;
		break;
	case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
		flags = VK_ACCESS_TRANSFER_WRITE_BIT;
		break;
	case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
		flags = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
		break;
	case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
		flags = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT;
		break;
	case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
		flags = VK_ACCESS_SHADER_READ_BIT;
		break;
	case VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL:
		flags = VK_ACCESS_SHADER_READ_BIT;
		break;
	case VK_IMAGE_LAYOUT_PRESENT_SRC_KHR:
		flags = VK_ACCESS_MEMORY_READ_BIT;
		break;
	case VK_IMAGE_LAYOUT_GENERAL:
		flags = 0;
		break;
	case VK_IMAGE_LAYOUT_UNDEFINED:
		flags = 0;
		break;
	case VK_IMAGE_LAYOUT_PREINITIALIZED:
		flags = VK_ACCESS_HOST_WRITE_BIT;
		break;
	default:
		assert(false);
		break;
	}
	return flags;
}

VkPipelineStageFlags Image::GetStageFlags(VkImageLayout layout)
{
	VkAccessFlags flags = 0;
	switch (layout)
	{
	case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
		flags = VK_PIPELINE_STAGE_TRANSFER_BIT;
		break;
	case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
		flags = VK_PIPELINE_STAGE_TRANSFER_BIT;
		break;
	case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
		flags = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		break;
	case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
		flags = VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT
				| VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT;
		break;
	case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
		flags = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
		break;
	case VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL:
		flags = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
		break;
	case VK_IMAGE_LAYOUT_PRESENT_SRC_KHR:
		flags = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
		break;
	case VK_IMAGE_LAYOUT_GENERAL:
		flags = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
		break;
	case VK_IMAGE_LAYOUT_UNDEFINED:
		flags = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
		break;
	default:
		assert(false);
		break;
	}
	return flags;
}

VkImageCreateInfo Image::CreateInfo(void)
{
	VkImageCreateInfo image_create_info = {};
	image_create_info.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
	image_create_info.pNext = nullptr;
	image_create_info.flags = 0;
	image_create_info.imageType = VK_IMAGE_TYPE_2D;
	image_create_info.format = VK_FORMAT_UNDEFINED;
	image_create_info.extent.width = 0;
	image_create_info.extent.height = 0;
	image_create_info.extent.depth = 0;
	image_create_info.mipLevels = 0;
	image_create_info.arrayLayers = 0;
	image_create_info.samples = VK_SAMPLE_COUNT_1_BIT;
	image_create_info.tiling = VK_IMAGE_TILING_OPTIMAL;
	image_create_info.usage = VK_IMAGE_USAGE_SAMPLED_BIT;
	image_create_info.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
	image_create_info.queueFamilyIndexCount = 0;
	image_create_info.pQueueFamilyIndices = nullptr;
//	image_create_info.initialLayout = VK_IMAGE_LAYOUT_PREINITIALIZED;
	image_create_info.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	return image_create_info;
}

SwapChainImage::SwapChainImage(Device* device):
		Image(device)
{
}

SwapChainImage::~SwapChainImage(void)
{
	mImage = VK_NULL_HANDLE;
}

VkResult SwapChainImage::Create(VkImage image, const VkImageCreateInfo* info)
{
	mImage = image;
	mInfo = *info;
	vkGetImageMemoryRequirements(mDevice->GetHandle(), mImage, &mRequirement);
	mResult = VK_SUCCESS;
	return mResult;
}


} /* namespace Vulkan */
