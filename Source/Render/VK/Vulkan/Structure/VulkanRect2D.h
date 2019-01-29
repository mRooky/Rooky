/*
 * VulkanRect2D.h
 *
 *  Created on: Dec 23, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_STRUCTURE_VULKANRECT2D_H_
#define VULKAN_STRUCTURE_VULKANRECT2D_H_

#include <vulkan/vulkan.h>

namespace Vulkan
{

class Rect2D: public VkRect2D
{
public:
	Rect2D(void);
	Rect2D(const VkRect2D& rect);
	Rect2D(const VkExtent2D& extent);
	Rect2D(const VkViewport& viewport);
	~Rect2D(void) = default;
};

inline Rect2D::Rect2D(void)
{
	offset.x = 0;
	offset.y = 0;
	extent.width = 0;
	extent.height = 0;
}

inline Rect2D::Rect2D(const VkRect2D& rect)
{
	offset = rect.offset;
	extent = rect.extent;
}

inline Rect2D::Rect2D(const VkExtent2D& other)
{
	offset.x = 0;
	offset.y = 0;
	extent.width = other.width;
	extent.height = other.height;
}

inline Rect2D::Rect2D(const VkViewport& other)
{
	offset.x = static_cast<int32_t>(other.x);
	offset.y = static_cast<int32_t>(other.y);
	extent.width = static_cast<uint32_t>(other.width);
	extent.height = static_cast<uint32_t>(other.height);
}

} /* namespace Vulkan */

#endif /* VULKAN_STRUCTURE_VULKANRECT2D_H_ */
