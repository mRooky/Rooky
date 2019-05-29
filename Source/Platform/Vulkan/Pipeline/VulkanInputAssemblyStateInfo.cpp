/*
 * VKInputAssemblyState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanInputAssemblyStateInfo.h"
#include "../VulkanPipeline.h"

#include <cassert>

namespace Vulkan
{

InputAssemblyStateInfo::InputAssemblyStateInfo(void)
{
	m_createInfo = Vulkan::Pipeline::InputAssemblyStateCreateInfo();
}

InputAssemblyStateInfo::~InputAssemblyStateInfo(void)
{
}

} /* namespace VK */
