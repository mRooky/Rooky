/*
 * VKDynamicStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanDynamicStateInfo.h"
#include "VulkanPipeline.h"

namespace Vulkan
{

DynamicStateInfo::DynamicStateInfo(void)
{
	m_createInfo = Vulkan::Pipeline::DynamicStateCreateInfo();
}

DynamicStateInfo::~DynamicStateInfo(void)
{
}

} /* namespace VK */
