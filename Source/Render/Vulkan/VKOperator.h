/*
 * VKOperator.h
 *
 *  Created on: Mar 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKOPERATOR_H_
#define SOURCE_RENDER_VK_VKOPERATOR_H_

#include "VKRender.h"

namespace VK
{

static inline VkExtent2D operator / (const VkExtent2D& extent, uint32_t div)
{
	VkExtent2D div_extent = { extent.width / div, extent.height / div };
	return div_extent;
}

static inline VkExtent2D operator / (const VkExtent3D& extent, uint32_t div)
{
	VkExtent2D div_extent = { extent.width / div, extent.height / div };
	return div_extent;
}

}

#endif /* SOURCE_RENDER_VK_VKOPERATOR_H_ */
