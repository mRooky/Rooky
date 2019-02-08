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
	mExtent.width = width;
	mExtent.height = height;
	mExtent.depth = depth;
	mUsage = usage;

	assert(mImage == nullptr);
	VkFormat vk_format = ConvertFormat(format);
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetDeviceVK();
	mImage = Vulkan::Image::New(device);
	mImage->Create(vk_format, width, height, depth, usage);

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

void Image::CreateView(Render::Image::Type type)
{
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
	assert(mSampler != nullptr);
	auto sampler = static_cast<Sampler*>(mSampler);
	VkDescriptorImageInfo descriptor_info = {};
	descriptor_info.sampler = sampler->GetSamplerVK()->GetHandle();
	descriptor_info.imageView = mImage->GetView()->GetHandle();
	descriptor_info.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
	return descriptor_info;
}

VkImageViewType Image::ConverType(const Render::Image::Type& type)
{
	switch (type)
	{
	case Render::Image::Type::IMAGE_1D:
		return VK_IMAGE_VIEW_TYPE_1D;
	case Render::Image::Type::IMAGE_2D:
		return VK_IMAGE_VIEW_TYPE_2D;
	case Render::Image::Type::IMAGE_3D:
		return VK_IMAGE_VIEW_TYPE_3D;
	case Render::Image::Type::IMAGE_CUBE:
		return VK_IMAGE_VIEW_TYPE_CUBE;
	case Render::Image::Type::IMAGE_1D_ARRAY:
		return VK_IMAGE_VIEW_TYPE_1D_ARRAY;
	case Render::Image::Type::IMAGE_2D_ARRAY:
		return VK_IMAGE_VIEW_TYPE_2D_ARRAY;
	case Render::Image::Type::IMAGE_CUBE_ARRAY:
		return VK_IMAGE_VIEW_TYPE_CUBE_ARRAY;
	default:
		assert(false);
		return VK_IMAGE_VIEW_TYPE_MAX_ENUM;
	}
}

Render::Image::Type Image::ConverType(const VkImageViewType& type)
{
	switch (type)
	{
	case VK_IMAGE_VIEW_TYPE_1D:
		return Render::Image::Type::IMAGE_1D;
	case VK_IMAGE_VIEW_TYPE_2D:
		return Render::Image::Type::IMAGE_2D;
	case VK_IMAGE_VIEW_TYPE_3D:
		return Render::Image::Type::IMAGE_3D;
	case VK_IMAGE_VIEW_TYPE_CUBE:
		return Render::Image::Type::IMAGE_CUBE;
	case VK_IMAGE_VIEW_TYPE_1D_ARRAY:
		return Render::Image::Type::IMAGE_1D_ARRAY;
	case VK_IMAGE_VIEW_TYPE_2D_ARRAY:
		return Render::Image::Type::IMAGE_2D_ARRAY;
	case VK_IMAGE_VIEW_TYPE_CUBE_ARRAY:
		return Render::Image::Type::IMAGE_CUBE_ARRAY;
	default:
		assert(false);
		return Render::Image::Type::IMAGE_UNKNOWN;
	}
}

} /* namespace VK */
