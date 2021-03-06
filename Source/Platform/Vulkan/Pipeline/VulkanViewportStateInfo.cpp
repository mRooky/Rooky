/*
 * VKViewportStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanViewportStateInfo.h"
#include "../VulkanPipeline.h"

namespace Vulkan
{

ViewportStateInfo::ViewportStateInfo(void)
{
	m_createInfo = Vulkan::Pipeline::ViewportStateCreateInfo();
}

ViewportStateInfo::~ViewportStateInfo(void)
{
}

void ViewportStateInfo::AppendScissor(VkRect2D scissor)
{
	m_scissors.push_back(scissor);
	m_createInfo.pScissors = m_scissors.data();
	m_createInfo.scissorCount = m_scissors.size();
}

void ViewportStateInfo::AppendViewport(VkViewport viewport)
{
	m_viewports.push_back(viewport);
	m_createInfo.pViewports = m_viewports.data();
	m_createInfo.viewportCount = m_viewports.size();
}

} /* namespace VK */
