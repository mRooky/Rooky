/*
 * VKMultisampleStateInfo.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#include "VKMultisampleStateInfo.h"
#include <VulkanPipeline.h>
#include <cassert>

namespace VK
{

MultisampleStateInfo::MultisampleStateInfo(void)
{
	*static_cast<VkPipelineMultisampleStateCreateInfo*>(this) = Vulkan::Pipeline::MultisampleStateCreateInfo();
}

MultisampleStateInfo::~MultisampleStateInfo(void)
{
}

} /* namespace VK */
