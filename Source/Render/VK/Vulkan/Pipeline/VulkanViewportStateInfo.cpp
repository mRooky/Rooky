/*
 * VKViewportStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanViewportStateInfo.h"
#include "VulkanPipeline.h"

namespace Vulkan
{

ViewportStateInfo::ViewportStateInfo(void)
{
	*static_cast<VkPipelineViewportStateCreateInfo*>(this) = Vulkan::Pipeline::ViewportStateCreateInfo();
}

ViewportStateInfo::~ViewportStateInfo(void)
{
}

void ViewportStateInfo::AppendScissor(VkRect2D scissor)
{
	mScissors.push_back(scissor);
	this->scissorCount = mScissors.size();
    this->pScissors = mScissors.data();
}

void ViewportStateInfo::AppendViewport(VkViewport viewport)
{
	mViewports.push_back(viewport);
	this->viewportCount = mViewports.size();
	this->pViewports = mViewports.data();
}

} /* namespace VK */
