/*
 * VKInline.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKINLINE_H_
#define SOURCE_RENDER_VK_VKINLINE_H_

#include "VKDefine.h"
#include <cassert>

namespace VK
{

static inline void NotImplemented(void)
{
	assert(false);
}

static inline VkMemoryPropertyFlags GetMemoryPropertyFlags(Render::HeapAccess access)
{
	switch(access)
	{
	case Render::HeapAccess::HEAP_ACCESS_GPU_ONLY:
		return VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
	case Render::HeapAccess::HEAP_ACCESS_CPU_VISIBLE:
		return VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT;
	default:
		assert(false);
		return VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
	}
}

static inline VkBufferUsageFlags ConvertBufferUsageFlag(uint32_t usage)
{
	VkBufferUsageFlags flags = 0;
	for (size_t index = 0; index < 7; ++index)
	{
		auto flag = RenderBufferUsages[index];
		uint32_t code = static_cast<uint32_t>(flag);
		if (usage & code)
		{
			flags |= VulkanBufferUsages[index];
		}
	}

	return flags;
}

static inline VkImageUsageFlags ConvertImageUsageFlag(uint32_t usage)
{
	VkImageUsageFlags flags = 0;
	for (size_t index = 0; index < 6; ++index)
	{
		auto flag = RenderImageUsages[index];
		uint32_t code = static_cast<uint32_t>(flag);
		if (usage & code)
		{
			flags |= VulkanImageUsages[index];
		}
	}

	return flags;
}

}

#endif /* SOURCE_RENDER_VK_VKINLINE_H_ */
