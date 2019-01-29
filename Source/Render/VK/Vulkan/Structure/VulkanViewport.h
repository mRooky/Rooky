/*
 * CViewport.h
 *
 *  Created on: Dec 23, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_STRUCTURE_VULKANVIEWPORT_H_
#define VULKAN_STRUCTURE_VULKANVIEWPORT_H_

#include <vulkan/vulkan.h>

namespace Vulkan
{

class Viewport: public VkViewport
{
public:
	Viewport(void);
	Viewport(const VkRect2D& rect);
	Viewport(const VkExtent2D& extent);
	~Viewport(void) = default;
};

inline Viewport::Viewport(void)
{
	x = 0.0f;
	y = 0.0f;
	width = 0.0f;
	height = 0.0f;
	minDepth = 0.0f;
	maxDepth = 1.0f;
}

inline Viewport::Viewport(const VkRect2D& other)
{
	x = static_cast<float>(other.offset.x);
	y = static_cast<float>(other.offset.y);
	width = static_cast<float>(other.extent.width);
	height = static_cast<float>(other.extent.height);
	minDepth = 0.0f;
	maxDepth = 1.0f;
}

inline Viewport::Viewport(const VkExtent2D& other)
{
	x = 0.0f;
	y = 0.0f;
	width = other.width;
	height = other.height;
	minDepth = 0.0f;
	maxDepth = 1.0f;
}

} /* namespace Vulkan */

#endif /* VULKAN_STRUCTURE_VULKANVIEWPORT_H_ */
