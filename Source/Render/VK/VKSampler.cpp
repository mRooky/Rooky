/*
 * VKSampler.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKSampler.h"
#include "VulkanSampler.h"
#include "VulkanInline.h"
#include "VKDevice.h"

#include "VulkanSampler.h"

#include <cassert>

namespace VK
{

Sampler::Sampler(Device* device):
		Render::Sampler(device)
{
}

Sampler::~Sampler(void)
{
	Vulkan::Release(mSampler);
}

void Sampler::Create(void)
{
	auto vk_device = static_cast<Device*>(mDevice);
	auto vulkan_device = vk_device->GetVulkanDevice();
	mSampler = Vulkan::Sampler::New(vulkan_device);
	VkFilter filter = Sampler::GetFilter(mFilterType);
	VkSamplerAddressMode address = Sampler::GetAddressMode(mAddressMode);
	VkSamplerMipmapMode mipmap = Sampler::GetMipmapMode(mMipmapMode);
	mSampler->Create(filter, address, mipmap);
	mValid = true;
}

VkFilter Sampler::GetFilter(Render::FilterType type)
{
	switch(type)
	{
	case Render::FilterType::FILTER_TYPE_NEAREST:
		return VK_FILTER_NEAREST;
	case Render::FilterType::FILTER_TYPE_LINEAR:
		return VK_FILTER_LINEAR;
	case Render::FilterType::FILTER_TYPE_CUBIC_IMG:
		return VK_FILTER_CUBIC_IMG;
	default:
		assert(false);
	}
	return VK_FILTER_MAX_ENUM;
}

VkSamplerMipmapMode Sampler::GetMipmapMode(Render::MipmapMode mode)
{
	switch(mode)
	{
	case Render::MipmapMode::MIPMAP_MODE_NEAREST:
		return VK_SAMPLER_MIPMAP_MODE_NEAREST;
	case Render::MipmapMode::MIPMAP_MODE_LINEAR:
		return VK_SAMPLER_MIPMAP_MODE_LINEAR;
	default:
		assert(false);
	}
	return VK_SAMPLER_MIPMAP_MODE_MAX_ENUM;
}

VkSamplerAddressMode Sampler::GetAddressMode(Render::AddressMode mode)
{
	switch(mode)
	{
	case Render::AddressMode::ADDRESS_MODE_REPEAT:
		return VK_SAMPLER_ADDRESS_MODE_REPEAT;
	case Render::AddressMode::ADDRESS_MODE_MIRRORED_REPEAT:
		return VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT;
	case Render::AddressMode::ADDRESS_MODE_CLAMP_TO_EDGE:
		return VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
	case Render::AddressMode::ADDRESS_MODE_CLAMP_TO_BORDER:
		return VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER;
	case Render::AddressMode::ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE:
		return VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE;
	default:
		assert(false);
	}
	return VK_SAMPLER_ADDRESS_MODE_MAX_ENUM;
}

} /* namespace VK */
