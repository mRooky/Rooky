/*
 * VKMultisampleStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VulkanMultisampleStateInfo.h"
#include "../VulkanPipeline.h"
#include <cassert>

namespace Vulkan
{

MultisampleStateInfo::MultisampleStateInfo(void)
{
	m_createInfo = Vulkan::Pipeline::MultisampleStateCreateInfo();
}

MultisampleStateInfo::~MultisampleStateInfo(void)
{
}

} /* namespace VK */
