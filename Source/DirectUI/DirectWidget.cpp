/*
 * DirectWidget.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#include "DirectWidget.h"
#include <cassert>

namespace Direct
{

Widget::Widget(Widget* parent):
		mParent(parent)
{
}

Widget::~Widget(void)
{
	mParent = nullptr;
}

VkImageCopy Widget::GetCopyRegion(void) const
{
	VkOffset3D offset = {};
	assert(false);

	VkExtent3D extent = {};
	assert(false);

	VkImageCopy image_copy = {};
	image_copy.srcSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	image_copy.srcSubresource.mipLevel = 1;
	image_copy.srcSubresource.layerCount = 1;
	image_copy.srcOffset = offset;
	image_copy.dstSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	image_copy.dstSubresource.mipLevel = 1;
	image_copy.dstSubresource.layerCount = 1;
	image_copy.dstOffset = offset;
	image_copy.extent = extent;
	return image_copy;
}

} /* namespace Direct */
