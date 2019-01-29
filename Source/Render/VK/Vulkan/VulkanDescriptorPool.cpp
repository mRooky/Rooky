/*
 * VulkanDescriptorPool.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanDescriptorPool.h"
#include "VulkanDevice.h"
#include "VulkanDescriptorSet.h"
#include "VulkanDescriptorSetLayout.h"
#include <cassert>

namespace Vulkan
{

DescriptorPool::DescriptorPool(Device* device):
		DeviceObject(device)
{
}

DescriptorPool::~DescriptorPool(void)
{
	for (auto set : m_sets)
	{
		set->Destroy();
	}
	m_sets.clear();
	for (auto layout : m_layouts)
	{
		layout->Destroy();
	}
	m_layouts.clear();
	VkDevice device = mDevice->GetHandle();
	vkDestroyDescriptorPool(device, m_pool, nullptr);
	m_pool = VK_NULL_HANDLE;
}

VkResult DescriptorPool::Create(uint32_t max, std::vector<VkDescriptorPoolSize> sizes)
{
	VkDescriptorPoolCreateInfo descriptor_pool_create_info = DescriptorPool::CreateInfo();
	descriptor_pool_create_info.maxSets = max;
	descriptor_pool_create_info.poolSizeCount = sizes.size();
	descriptor_pool_create_info.pPoolSizes = sizes.data();
	return Create(&descriptor_pool_create_info);
}

VkResult DescriptorPool::Create(const VkDescriptorPoolCreateInfo* info)
{
	mResult = vkCreateDescriptorPool(mDevice->GetHandle(), info, nullptr, &m_pool);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

DescriptorSet* DescriptorPool::Allocate(DescriptorSetLayout* layout)
{
	DescriptorSet* set = Vulkan::DescriptorSet::New(mDevice);
	set->Create(this, layout);
	m_sets.push_back(set);
	return set;
}

DescriptorSetLayout* DescriptorPool::GetLayout(const std::vector<VkDescriptorSetLayoutBinding>& bindings)
{
	for (auto layout : m_layouts)
	{
		if(layout->IsCreateBy(bindings))
		{
			return layout;
		}
	}

	DescriptorSetLayout* layout = Vulkan::DescriptorSetLayout::New(mDevice);
	layout->Create(bindings);
	m_layouts.push_back(layout);
	return layout;
}

VkDescriptorPoolCreateInfo DescriptorPool::CreateInfo(void)
{
	VkDescriptorPoolCreateInfo descriptor_pool_create_info = {};
	descriptor_pool_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
	descriptor_pool_create_info.pNext = nullptr;
	descriptor_pool_create_info.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
	descriptor_pool_create_info.maxSets = 0;
	descriptor_pool_create_info.poolSizeCount = 0;
	descriptor_pool_create_info.pPoolSizes = nullptr;
	return descriptor_pool_create_info;
}

} /* namespace Vulkan */
