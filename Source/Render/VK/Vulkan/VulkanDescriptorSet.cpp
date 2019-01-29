/*
 * VulkanDescriptorSet.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanDescriptorSet.h"
#include "VulkanDescriptorSetLayout.h"
#include "VulkanDevice.h"
#include "VulkanDescriptorPool.h"
#include <cassert>

namespace Vulkan
{

DescriptorSet::DescriptorSet(Device* device):
		DeviceObject(device)
{
}

DescriptorSet::~DescriptorSet(void)
{
	VkDevice device = mDevice->GetHandle();
	VkDescriptorPool pool = m_pool->GetHandle();
	vkFreeDescriptorSets(device, pool, 1, &m_set);
	m_set = VK_NULL_HANDLE;
	m_pool = nullptr;
}

VkResult DescriptorSet::Create(DescriptorPool* pool, DescriptorSetLayout* layout)
{
	m_pool = pool;
	m_layout = layout;
	VkDescriptorSetLayout handle = layout->GetHandle();
	VkDescriptorSetAllocateInfo descriptor_set_allocate_info = DescriptorSet::AllocateInfo();
	descriptor_set_allocate_info.descriptorPool = m_pool->GetHandle();;
	descriptor_set_allocate_info.descriptorSetCount = 1;;
	descriptor_set_allocate_info.pSetLayouts = &handle;
	return Create(&descriptor_set_allocate_info);
}

VkResult DescriptorSet::Create(const VkDescriptorSetAllocateInfo* info)
{
	assert(info->descriptorSetCount == 1);
	mResult = vkAllocateDescriptorSets(mDevice->GetHandle(), info, &m_set);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

void DescriptorSet::UpdateSets(Device* device, const std::vector<VkWriteDescriptorSet>& writes)
{
	DescriptorSet::UpdateSets(device, writes.size(), writes.data());
}

void DescriptorSet::UpdateSets(Device* device, uint32_t count, const VkWriteDescriptorSet* write)
{
	VkDevice handle = device->GetHandle();
	vkUpdateDescriptorSets(handle, count, write, 0, nullptr);
}

VkDescriptorSetAllocateInfo DescriptorSet::AllocateInfo(void)
{
	VkDescriptorSetAllocateInfo descriptor_set_allocate_info;
	descriptor_set_allocate_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
	descriptor_set_allocate_info.pNext = nullptr;
	descriptor_set_allocate_info.descriptorPool = VK_NULL_HANDLE;
	descriptor_set_allocate_info.descriptorSetCount = 0;
	descriptor_set_allocate_info.pSetLayouts = nullptr;
	return descriptor_set_allocate_info;
}

VkWriteDescriptorSet DescriptorSet::WriteDescriptorSet(void)
{
	VkWriteDescriptorSet write_descriptor_set = {};
	write_descriptor_set.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
	write_descriptor_set.dstSet = VK_NULL_HANDLE;
	write_descriptor_set.descriptorCount = 0;
	write_descriptor_set.descriptorType = VK_DESCRIPTOR_TYPE_MAX_ENUM;
	write_descriptor_set.pBufferInfo = nullptr;
	write_descriptor_set.dstBinding = 0;
	return write_descriptor_set;
}

} /* namespace Vulkan */
