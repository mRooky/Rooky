/*
 * VulkanPipelineLayout.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanPipelineLayout.h"
#include "VulkanDevice.h"
#include "VulkanDescriptorSetLayout.h"
#include <cassert>

namespace Vulkan
{

PipelineLayout::PipelineLayout(Device* device):
		DeviceObject(device)
{
}

PipelineLayout::~PipelineLayout(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyPipelineLayout(device, m_layout, nullptr);
	m_layout = VK_NULL_HANDLE;
}

VkResult PipelineLayout::Create(const std::vector<DescriptorSetLayout*>& layouts)
{
	assert(layouts.size() > 0);
	std::vector<VkDescriptorSetLayout> handles;
	handles.reserve(layouts.size());
	for (auto layout : layouts)
	{
		handles.push_back(layout->GetHandle());
	}
	return Create(handles);
}

VkResult PipelineLayout::Create(const std::vector<VkDescriptorSetLayout>& layouts)
{
	VkPipelineLayoutCreateInfo pipeline_layout_create_info = PipelineLayout::CreateInfo();
	pipeline_layout_create_info.setLayoutCount = layouts.size();
	pipeline_layout_create_info.pSetLayouts = layouts.data();
	pipeline_layout_create_info.pushConstantRangeCount = 0;
	pipeline_layout_create_info.pPushConstantRanges = nullptr;
	return Create(&pipeline_layout_create_info);
}

VkResult PipelineLayout::Create(const std::vector<VkDescriptorSetLayout>& layouts, const std::vector<VkPushConstantRange>& ranges)
{
	VkPipelineLayoutCreateInfo pipeline_layout_create_info = PipelineLayout::CreateInfo();
	pipeline_layout_create_info.setLayoutCount = layouts.size();
	pipeline_layout_create_info.pSetLayouts = layouts.data();
	pipeline_layout_create_info.pushConstantRangeCount = ranges.size();
	pipeline_layout_create_info.pPushConstantRanges = ranges.data();
	return Create(&pipeline_layout_create_info);
}

VkResult PipelineLayout::Create(const std::vector<DescriptorSetLayout*>& layouts, uint32_t count, const VkPushConstantRange* ranges)
{
	assert(layouts.size() > 0);
	std::vector<VkDescriptorSetLayout> handles;
	handles.reserve(layouts.size());
	for (auto layout : layouts)
	{
		handles.push_back(layout->GetHandle());
	}

	VkPipelineLayoutCreateInfo pipeline_layout_create_info = PipelineLayout::CreateInfo();
	pipeline_layout_create_info.setLayoutCount = handles.size();
	pipeline_layout_create_info.pSetLayouts = handles.data();
	pipeline_layout_create_info.pushConstantRangeCount = count;
	pipeline_layout_create_info.pPushConstantRanges = ranges;
	return Create(&pipeline_layout_create_info);
}

VkResult PipelineLayout::Create(const VkPipelineLayoutCreateInfo* info)
{
	mResult = vkCreatePipelineLayout(mDevice->GetHandle(), info, nullptr, &m_layout);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

VkPipelineLayoutCreateInfo PipelineLayout::CreateInfo(void)
{
	VkPipelineLayoutCreateInfo pipeline_layout_create_info = {};
	pipeline_layout_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
	pipeline_layout_create_info.pNext = nullptr;
	pipeline_layout_create_info.flags = 0;
	pipeline_layout_create_info.setLayoutCount = 0;
	pipeline_layout_create_info.pSetLayouts = nullptr;
	pipeline_layout_create_info.pushConstantRangeCount = 0;
	pipeline_layout_create_info.pPushConstantRanges = nullptr;
	return pipeline_layout_create_info;
}

} /* namespace Vulkan */
