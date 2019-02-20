/*
 * VKColorBlendAttachmentState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanColorBlendAttachmentState.h"
#include "VulkanPipeline.h"
#include <cassert>

namespace Vulkan
{

ColorBlendAttachmentState::ColorBlendAttachmentState(void)
{
	*static_cast<VkPipelineColorBlendAttachmentState*>(this) = Vulkan::Pipeline::ColorBlendAttachmentState(false);
}

ColorBlendAttachmentState::~ColorBlendAttachmentState(void)
{
}

} /* namespace VK */
