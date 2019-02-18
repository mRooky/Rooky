/*
 * VKColorBlendStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKColorBlendStateInfo.h"

#include "VulkanPipeline.h"

#include <cassert>

namespace VK
{

ColorBlendStateInfo::ColorBlendStateInfo(void)
{
	mStates.reserve(8);
	*static_cast<VkPipelineColorBlendStateCreateInfo*>(this) = Vulkan::Pipeline::ColorBlendStateCreateInfo();
}

ColorBlendStateInfo::~ColorBlendStateInfo(void)
{
}

ColorBlendAttachmentState* ColorBlendStateInfo::CreateState(void)
{
	mStates.push_back(ColorBlendAttachmentState());
	this->pAttachments = mStates.data();
	this->attachmentCount = mStates.size();
	return &mStates.back();
}

} /* namespace VK */
