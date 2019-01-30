/*
 * VKImage.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKImage.h"
#include "VKContext.h"
#include "VKFormat.h"
#include "VKMemory.h"
#include "VKSampler.h"

#include "VulkanImage.h"
#include "VulkanImageView.h"
#include "VulkanSampler.h"
#include "VulkanInline.h"

#include <cassert>

namespace VK
{

Image::Image(Context* context):
		Render::Image(context)
{
}

Image::~Image(void)
{
	Vulkan::Release(mImage);
}

void Image::Initialize(Render::Format format, uint32_t width, uint32_t height, uint32_t depth, uint32_t usage)
{
	mFormat = format;
	mWidth = width;
	mHeight = height;
	mUsage = usage;

	VkExtent3D extent = { width, height, depth};
	VkFormat vk_format = ConvertFormat(format);
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetDeviceVK();

	assert(mImage == nullptr);
	mImage = Vulkan::Image::New(device);
	mImage->Create(vk_format, extent, usage);

}

void Image::BindMemory(Render::Memory* memory, size_t offset)
{
	assert(memory != nullptr);
	assert(mMemory == nullptr);
	mMemory = memory;
	mOffset = offset;
	Memory* vk_memory = static_cast<Memory*>(memory);
	mImage->BindMemory(vk_memory->GetMemoryVK(), mOffset);
}

void Image::CreateView(void)
{
	assert(mMemory != nullptr);
	mImage->CreateView(VK_IMAGE_VIEW_TYPE_2D);
}

VkDescriptorImageInfo Image::GetDescriptorInfo(void) const
{
	assert(mImage != nullptr);
	assert(mMemory != nullptr);
	auto view = mImage->GetView();
	assert(view != nullptr);
	assert(mSampler != nullptr);
	auto sampler = static_cast<Sampler*>(mSampler);
	VkDescriptorImageInfo descriptor_info = {};
	descriptor_info.sampler = sampler->GetSamplerVK()->GetHandle();
	descriptor_info.imageView = mImage->GetView()->GetHandle();
	descriptor_info.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
	return descriptor_info;
}

} /* namespace VK */
