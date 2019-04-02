/*
 * VulkanDescriptorSetLayout.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanDescriptorSetLayout.h"
#include "VulkanDevice.h"
#include "VulkanUtility.h"

#include <cstring>
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
	assert(m_layout == VK_NULL_HANDLE);
	mBindings = bindings;
	auto descriptor_set_layout_create_info = DescriptorSetLayout::CreateInfo();
	descriptor_set_layout_create_info.bindingCount = bindings.size();
	descriptor_set_layout_create_info.pBindings = bindings.data();
	return Create(&descriptor_set_layout_create_info);
}

VkResult DescriptorSetLayout::Create(uint32_t count, const VkDescriptorSetLayoutBinding* bindings)
{
	assert(mBindings.size() == 0);
	assert(m_layout == VK_NULL_HANDLE);
	mBindings.resize(count);
	size_t size = sizeof(VkDescriptorSetLayoutBinding) * count;
	std::memcpy(mBindings.data(), bindings, size);
	auto descriptor_set_layout_create_info = DescriptorSetLayout::CreateInfo();
	descriptor_set_layout_create_info.bindingCount = mBindings.size();
	descriptor_set_layout_create_info.pBindings = mBindings.data();
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
	return IsCreateBy(bindings.size(), bindings.data());
}

bool DescriptorSetLayout::IsCreateBy(uint32_t count, const VkDescriptorSetLayoutBinding* bindings) const
{
	assert(count > 0);
	if (count == mBindings.size())
	{
		for (size_t index = 0; index < count; ++index)
		{
			auto& binding = *(bindings + index);
			if (!(mBindings.at(index) == binding))
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
