/*
 * VKColorBlendStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanColorBlendStateInfo.h"
#include "../VulkanPipeline.h"

#include <cassert>

namespace Vulkan
{

ColorBlendStateInfo::ColorBlendStateInfo(void)
{
	m_states.reserve(8);
	m_createInfo = Vulkan::Pipeline::ColorBlendStateCreateInfo();
}

ColorBlendStateInfo::~ColorBlendStateInfo(void)
{
}

VkPipelineColorBlendAttachmentState* ColorBlendStateInfo::CreateAttachmentState(bool blend)
{
	auto attachement_state = Vulkan::Pipeline::ColorBlendAttachmentState(blend);
	m_states.push_back(attachement_state);
	m_createInfo.pAttachments = m_states.data();
	m_createInfo.attachmentCount = m_states.size();
	return &m_states.back();
}

void ColorBlendStateInfo::SetColor(size_t index, VkBlendFactor src, VkBlendFactor dst, VkBlendOp operation)
{
	VkPipelineColorBlendAttachmentState& state = m_states.at(index);
	state.srcColorBlendFactor = src;
	state.dstColorBlendFactor = dst;
	state.colorBlendOp = operation;
}

void ColorBlendStateInfo::SetAlpha(size_t index, VkBlendFactor src, VkBlendFactor dst, VkBlendOp operation)
{
	VkPipelineColorBlendAttachmentState& state = m_states.at(index);
	state.srcAlphaBlendFactor = src;
	state.dstAlphaBlendFactor = dst;
	state.alphaBlendOp = operation;
}
} /* namespace VK */
