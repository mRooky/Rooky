/*
 * UIBitmap.cpp
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#include "DirectContext.h"
#include "DirectTarget.h"
#include "../Platform/Vulkan/VulkanImage.h"
#include "../Platform/Vulkan/VulkanDeviceMemory.h"
#include "../Platform/Vulkan/VulkanInline.h"
#include <cassert>

namespace Direct
{

Target::Target(void)
{
}

Target::~Target(void)
{
	mSampler = nullptr;
	Vulkan::Release(mImage);
	Vulkan::Release(mMemory);
}

void Target::CreateImage(uint32_t width, uint32_t height, VkFormat format)
{
	mWidth = width;
	mHeight = height;
	mFormat = format;

	VkExtent3D extent = {width, height, 1};
	VkImageUsageFlags usage = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;
	Vulkan::Device* device = Context::GetContext()->GetDevice();
	mImage = Vulkan::Image::New(device);
	mImage->Create(mFormat, extent, usage);
}

void Target::CreateMemory(VkMemoryPropertyFlags property)
{
	assert(mImage != nullptr);
	Vulkan::Device* device = Context::GetContext()->GetDevice();
	mMemory = Vulkan::DeviceMemory::New(device);
	mMemory->Allocate(mImage, property);
}

void Target::BindingMemory(Vulkan::DeviceMemory* memory)
{
	assert(memory == nullptr);
	assert(mImage != nullptr);
	assert(mMemory != nullptr);
	mImage->BindMemory(mMemory, 0);
	mImage->CreateView(VK_IMAGE_VIEW_TYPE_2D);
}

} /* namespace UI */
