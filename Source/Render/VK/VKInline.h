/*
 * VKInline.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKINLINE_H_
#define SOURCE_RENDER_VK_VKINLINE_H_

#include "VulkanClasses.h"

namespace VK
{

static inline VkMemoryPropertyFlags GetMemoryPropertyFlags(bool mappable)
{
	return (mappable ? VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT : VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
}

}

#endif /* SOURCE_RENDER_VK_VKINLINE_H_ */
