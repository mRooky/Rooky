/*
 * VulkanImageView.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanImageView.h"
#include "VulkanDevice.h"
#include "VulkanImage.h"
#include <cassert>
#include <algorithm>

namespace Vulkan
{

ImageView::ImageView(Device* device):
		DeviceObject(device)
{
}

ImageView::~ImageView(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyImageView(device, m_view, nullptr);
	m_view = VK_NULL_HANDLE;
	m_image = nullptr;
}

VkResult ImageView::Create(Image* image, VkImageViewType type, VkImageSubresourceRange range)
{
	m_image = image;
	VkFormat format = image->GetFormat();
	VkImageViewCreateInfo image_view_create_info = ImageView::CreateInfo();
	image_view_create_info.image = image->GetHandle();
	image_view_create_info.viewType = type;
	image_view_create_info.format = format;
	image_view_create_info.subresourceRange = range;
	return Create(&image_view_create_info);
}

VkResult ImageView::Create(const VkImageViewCreateInfo* info)
{
	mResult = vkCreateImageView(mDevice->GetHandle(), info, nullptr, &m_view);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

bool ImageView::IsDepthFormat(VkFormat format)
{
	const static std::vector<VkFormat> depth_formats =
	{
		VK_FORMAT_D32_SFLOAT_S8_UINT,
		VK_FORMAT_D32_SFLOAT,
		VK_FORMAT_D24_UNORM_S8_UINT,
		VK_FORMAT_D16_UNORM_S8_UINT,
		VK_FORMAT_D16_UNORM
	};
	auto iterator = std::find(depth_formats.begin(), depth_formats.end(), format);
	return iterator != depth_formats.end();
}

VkImageAspectFlags ImageView::GetAspectFlags(VkFormat format)
{
	switch(format)
	{
	case VK_FORMAT_D32_SFLOAT_S8_UINT:
		return VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
		break;
	case VK_FORMAT_D32_SFLOAT:
		return VK_IMAGE_ASPECT_DEPTH_BIT;
		break;
	case VK_FORMAT_D24_UNORM_S8_UINT:
		return VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
		break;
	case VK_FORMAT_D16_UNORM_S8_UINT:
		return VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
		break;
	case VK_FORMAT_D16_UNORM:
		return VK_IMAGE_ASPECT_DEPTH_BIT;
		break;
	default:
		return VK_IMAGE_ASPECT_COLOR_BIT;
		break;
	}
	return VK_IMAGE_ASPECT_COLOR_BIT;
}

VkImageViewCreateInfo ImageView::CreateInfo(void)
{
	VkImageViewCreateInfo image_view_create_info = {};
	image_view_create_info.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	image_view_create_info.pNext = NULL;
	image_view_create_info.flags = 0;
	image_view_create_info.image = VK_NULL_HANDLE;
	image_view_create_info.viewType = VK_IMAGE_VIEW_TYPE_2D;
	image_view_create_info.format = VK_FORMAT_UNDEFINED;
	image_view_create_info.components.r = VK_COMPONENT_SWIZZLE_R;
	image_view_create_info.components.g = VK_COMPONENT_SWIZZLE_G;
	image_view_create_info.components.b = VK_COMPONENT_SWIZZLE_B;
	image_view_create_info.components.a = VK_COMPONENT_SWIZZLE_A;
	image_view_create_info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_FLAG_BITS_MAX_ENUM;
	image_view_create_info.subresourceRange.baseMipLevel = 0;
	image_view_create_info.subresourceRange.levelCount = 0;
	image_view_create_info.subresourceRange.baseArrayLayer = 0;
	image_view_create_info.subresourceRange.layerCount = 0;
	return image_view_create_info;
}

} /* namespace Vulkan */
