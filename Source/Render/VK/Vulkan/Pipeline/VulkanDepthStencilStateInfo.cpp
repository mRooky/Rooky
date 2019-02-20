/*
 * VKDepthStencilStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanDepthStencilStateInfo.h"
#include "VulkanPipeline.h"
#include <cassert>

namespace Vulkan
{

DepthStencilStateInfo::DepthStencilStateInfo(void)
{
	*static_cast<VkPipelineDepthStencilStateCreateInfo*>(this) = Vulkan::Pipeline::DepthStencilStateCreateInfo();
}

DepthStencilStateInfo::~DepthStencilStateInfo(void)
{
}

} /* namespace VK */
