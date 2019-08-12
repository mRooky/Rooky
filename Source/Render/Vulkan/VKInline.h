/*
 * VKInline.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKINLINE_H_
#define SOURCE_RENDER_VK_VKINLINE_H_

#include "VKDefine.h"
#include "../../Core/GHI/GHIResourceUsage.h"

#include <vulkan/vulkan.h>
#include <cassert>

namespace VK
{

static inline void NotImplemented(void)
{
	assert(false);
}

static inline VkMemoryPropertyFlags GetMemoryPropertyFlags(GHI::ResourceUsage& usage)
{
	if (usage.memoryType.cpuAccess == 1)
	{
		return VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT
			| VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
	}
	else
	{
		return VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
	}
}

}

#endif /* SOURCE_RENDER_VK_VKINLINE_H_ */
