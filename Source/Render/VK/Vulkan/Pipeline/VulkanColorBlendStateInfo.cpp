/*
 * VKColorBlendStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanColorBlendStateInfo.h"
#include "VulkanPipeline.h"

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

ColorBlendAttachmentState* ColorBlendStateInfo::CreateAttachmentState(void)
{
	m_states.push_back(ColorBlendAttachmentState());
	m_createInfo.pAttachments = m_states.data();
	m_createInfo.attachmentCount = m_states.size();
	return &m_states.back();
}

} /* namespace VK */
