/*
 * VKDynamicStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanDynamicStateInfo.h"
#include "../VulkanPipeline.h"

namespace Vulkan
{

DynamicStateInfo::DynamicStateInfo(void)
{
	m_createInfo = Vulkan::Pipeline::DynamicStateCreateInfo();
	m_dynamicStates.push_back(VK_DYNAMIC_STATE_VIEWPORT);
	m_dynamicStates.push_back(VK_DYNAMIC_STATE_SCISSOR);
	m_createInfo.dynamicStateCount = m_dynamicStates.size();
	m_createInfo.pDynamicStates = m_dynamicStates.data();
}

DynamicStateInfo::~DynamicStateInfo(void)
{
}

} /* namespace VK */
