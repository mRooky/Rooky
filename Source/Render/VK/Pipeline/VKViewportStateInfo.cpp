/*
 * VKViewportStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKViewportStateInfo.h"
#include "VulkanPipeline.h"

namespace VK
{

ViewportStateInfo::ViewportStateInfo(void)
{
	*static_cast<VkPipelineViewportStateCreateInfo*>(this) = Vulkan::Pipeline::ViewportStateCreateInfo();
}

ViewportStateInfo::~ViewportStateInfo(void)
{
}

void ViewportStateInfo::SetScissor(Render::Rect2D scissor)
{
	VkRect2D vk_scissor = {};
	vk_scissor.offset.x = scissor.offset.x;
	vk_scissor.offset.y = scissor.offset.y;
	vk_scissor.extent.width = scissor.extent.width;
	vk_scissor.extent.height = scissor.extent.height;
	mScissors.push_back(vk_scissor);

	this->scissorCount = mScissors.size();
    this->pScissors = mScissors.data();
}

void ViewportStateInfo::SetViewport(Render::Viewport viewport)
{
	VkViewport vk_viewport = {};
	vk_viewport.x = viewport.x;
	vk_viewport.y = viewport.y;
	vk_viewport.width = viewport.width;
	vk_viewport.height = viewport.height;
	vk_viewport.minDepth = viewport.minDepth;
	vk_viewport.maxDepth = viewport.maxDepth;
	mViewports.push_back(vk_viewport);

	this->viewportCount = mViewports.size();
	this->pViewports = mViewports.data();
}

} /* namespace VK */
