/*
 * VKSampler.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKSampler.h"
#include "../../Platform/Vulkan/VulkanSampler.h"
#include "../../Platform/Vulkan/VulkanInline.h"
#include "../../Platform/Vulkan/VulkanSampler.h"
#include "VKDevice.h"

#include <cassert>

namespace VK
{

Sampler::Sampler(Device* device):
		GHI::Sampler(device)
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
	VkSamplerAddressMode address_u = Sampler::GetAddressMode(mAddressModeU);
	VkSamplerMipmapMode mipmap = Sampler::GetMipmapMode(mMipmapMode);
	mSampler->Create(filter, address_u, mipmap);
	mValid = true;
}

VkFilter Sampler::GetFilter(GHI::FilterType type)
{
	switch(type)
	{
	case GHI::FilterType::NEAREST:
		return VK_FILTER_NEAREST;
	case GHI::FilterType::LINEAR:
		return VK_FILTER_LINEAR;
	case GHI::FilterType::CUBIC_IMG:
		return VK_FILTER_CUBIC_IMG;
	default:
		assert(false);
	}
	return VK_FILTER_MAX_ENUM;
}

VkSamplerMipmapMode Sampler::GetMipmapMode(GHI::MipmapMode mode)
{
	switch(mode)
	{
	case GHI::MipmapMode::NEAREST:
		return VK_SAMPLER_MIPMAP_MODE_NEAREST;
	case GHI::MipmapMode::LINEAR:
		return VK_SAMPLER_MIPMAP_MODE_LINEAR;
	default:
		assert(false);
	}
	return VK_SAMPLER_MIPMAP_MODE_MAX_ENUM;
}

VkSamplerAddressMode Sampler::GetAddressMode(GHI::AddressMode mode)
{
	switch(mode)
	{
	case GHI::AddressMode::REPEAT:
		return VK_SAMPLER_ADDRESS_MODE_REPEAT;
	case GHI::AddressMode::MIRRORED_REPEAT:
		return VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT;
	case GHI::AddressMode::CLAMP_TO_EDGE:
		return VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
	case GHI::AddressMode::CLAMP_TO_BORDER:
		return VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER;
	case GHI::AddressMode::MIRROR_CLAMP_TO_EDGE:
		return VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE;
	default:
		assert(false);
	}
	return VK_SAMPLER_ADDRESS_MODE_MAX_ENUM;
}

} /* namespace VK */
