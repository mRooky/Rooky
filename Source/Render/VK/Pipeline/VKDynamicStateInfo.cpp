/*
 * VKDynamicStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKDynamicStateInfo.h"
#include "VulkanPipeline.h"

namespace VK
{

DynamicStateInfo::DynamicStateInfo(void)
{
	*static_cast<VkPipelineDynamicStateCreateInfo*>(this) = Vulkan::Pipeline::DynamicStateCreateInfo();
}

DynamicStateInfo::~DynamicStateInfo(void)
{
}

} /* namespace VK */
