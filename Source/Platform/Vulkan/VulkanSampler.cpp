/*
 * VulkanSampler.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanSampler.h"
#include "VulkanDevice.h"
#include <cassert>
#include <cstring>

namespace Vulkan
{

Sampler::Sampler(Device* device):
		DeviceObject(device)
{
}

Sampler::~Sampler(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroySampler(device, m_sampler, nullptr);
	m_sampler = VK_NULL_HANDLE;
}

VkResult Sampler::Create(VkFilter filter, VkSamplerAddressMode address, VkSamplerMipmapMode mipmap)
{
	VkSamplerCreateInfo sampler_create_info = Sampler::CreateInfo();
	sampler_create_info.magFilter = filter;
	sampler_create_info.minFilter = filter;
	sampler_create_info.mipmapMode = mipmap;
	sampler_create_info.addressModeU = address;
	sampler_create_info.addressModeV = address;
	sampler_create_info.addressModeW = address;
	return Create(&sampler_create_info);
}

VkResult Sampler::Create(const VkSamplerCreateInfo* info)
{
	mResult = vkCreateSampler(mDevice->GetHandle(), info, nullptr, &m_sampler);
	assert(mResult == VK_SUCCESS);
	std::memcpy(&m_info, info, sizeof(m_info));
	return mResult;
}

VkDescriptorImageInfo Sampler::GetDescriptorInfo(void) const
{
	VkDescriptorImageInfo descriptor_sampler_info = {};
	descriptor_sampler_info.sampler = m_sampler;
	descriptor_sampler_info.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
	return descriptor_sampler_info;
}

VkSamplerCreateInfo Sampler::CreateInfo(void)
{
	VkSamplerCreateInfo sampler_create_info = {};
	sampler_create_info.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
	sampler_create_info.magFilter = VK_FILTER_NEAREST;
	sampler_create_info.minFilter = VK_FILTER_NEAREST;
	sampler_create_info.mipmapMode = VK_SAMPLER_MIPMAP_MODE_NEAREST;
	sampler_create_info.addressModeU = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
	sampler_create_info.addressModeV = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
	sampler_create_info.addressModeW = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
	sampler_create_info.mipLodBias = 0.0f;
	sampler_create_info.anisotropyEnable = VK_FALSE;
	sampler_create_info.maxAnisotropy = 1.0f;
	sampler_create_info.compareOp = VK_COMPARE_OP_NEVER;
	sampler_create_info.minLod = 0.0f;
	sampler_create_info.maxLod = 0.0f;
	sampler_create_info.compareEnable = VK_FALSE;
	sampler_create_info.borderColor = VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE;
	sampler_create_info.unnormalizedCoordinates = VK_FALSE;
	return sampler_create_info;
}

} /* namespace Vulkan */
