/*
 * VKInputAssemblyState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanInputAssemblyStateInfo.h"
#include "VulkanPipeline.h"

#include <cassert>

namespace Vulkan
{

InputAssemblyStateInfo::InputAssemblyStateInfo(void)
{
	*static_cast<VkPipelineInputAssemblyStateCreateInfo*>(this) = Vulkan::Pipeline::InputAssemblyStateCreateInfo();
}

InputAssemblyStateInfo::~InputAssemblyStateInfo(void)
{
}

} /* namespace VK */
