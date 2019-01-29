/*
 * VulkanDescriptorSetLayout.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanDescriptorSetLayout.h"
#include "VulkanDevice.h"
#include "VulkanUtility.h"
#include <cassert>

namespace Vulkan
{

DescriptorSetLayout::DescriptorSetLayout(Device* device):
		DeviceObject(device)
{
}

DescriptorSetLayout::~DescriptorSetLayout(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyDescriptorSetLayout(device, m_layout, nullptr);
	m_layout = VK_NULL_HANDLE;
}

VkResult DescriptorSetLayout::Create(const std::vector<VkDescriptorSetLayoutBinding>& bindings)
{
	for (auto binding : bindings)
	{
		mBindings.push_back(binding);
	}
	VkDescriptorSetLayoutCreateInfo descriptor_set_layout_create_info = DescriptorSetLayout::CreateInfo();
	descriptor_set_layout_create_info.bindingCount = bindings.size();
	descriptor_set_layout_create_info.pBindings = bindings.data();
	return Create(&descriptor_set_layout_create_info);
}

VkResult DescriptorSetLayout::Create(const VkDescriptorSetLayoutCreateInfo* info)
{
	mResult = vkCreateDescriptorSetLayout(mDevice->GetHandle(), info, nullptr, &m_layout);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

bool DescriptorSetLayout::IsCreateBy(const std::vector<VkDescriptorSetLayoutBinding>& bindings) const
{
	assert(mBindings.size() > 0);
	if (bindings.size() == mBindings.size())
	{
		const size_t count = bindings.size();
		for (size_t index = 0; index < count; ++index)
		{
			bool equal = mBindings.at(index) == bindings.at(index);
			if (!equal)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

VkDescriptorSetLayoutBinding DescriptorSetLayout::Binding(void)
{
	VkDescriptorSetLayoutBinding descriptor_set_layout_binding = {};
	descriptor_set_layout_binding.binding = 0;
	descriptor_set_layout_binding.descriptorType = VK_DESCRIPTOR_TYPE_MAX_ENUM;
	descriptor_set_layout_binding.descriptorCount = 0;
	descriptor_set_layout_binding.stageFlags = VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM;
	descriptor_set_layout_binding.pImmutableSamplers = nullptr;
	return descriptor_set_layout_binding;
}

VkDescriptorSetLayoutCreateInfo DescriptorSetLayout::CreateInfo(void)
{
	VkDescriptorSetLayoutCreateInfo descriptor_set_layout_create_info = {};
	descriptor_set_layout_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
	descriptor_set_layout_create_info.pNext = nullptr;
	descriptor_set_layout_create_info.flags = 0;
	descriptor_set_layout_create_info.bindingCount = 0;
	descriptor_set_layout_create_info.pBindings = nullptr;
	return descriptor_set_layout_create_info;
}

} /* namespace Vulkan */
