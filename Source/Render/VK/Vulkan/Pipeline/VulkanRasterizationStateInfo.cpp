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
	m_createInfo = Vulkan::Pipeline::RasterizationStateCreateInfo();
}

RasterizationStateInfo::~RasterizationStateInfo(void)
{
}

} /* namespace VK */
