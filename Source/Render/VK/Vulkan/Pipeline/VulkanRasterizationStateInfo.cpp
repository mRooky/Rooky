/*
 * VKRasterizationState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanRasterizationStateInfo.h"
#include "VulkanPipeline.h"

#include <cassert>

namespace Vulkan
{

RasterizationStateInfo::RasterizationStateInfo(void)
{
	*static_cast<VkPipelineRasterizationStateCreateInfo*>(this) = Vulkan::Pipeline::RasterizationStateCreateInfo();
}

RasterizationStateInfo::~RasterizationStateInfo(void)
{
}

} /* namespace VK */
