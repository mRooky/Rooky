/*
 * VulkanExtent3D.h
 *
 *  Created on: Dec 23, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_STRUCTURE_VULKANEXTENT3D_H_
#define VULKAN_STRUCTURE_VULKANEXTENT3D_H_

#include <vulkan/vulkan.h>

namespace Vulkan
{

class Extent3D: public VkExtent3D
{
public:
	Extent3D(void);
	Extent3D(const VkExtent2D& extent);
	~Extent3D(void) = default;
};

inline Extent3D::Extent3D(void)
{
	width = 0;
	height = 0;
	depth = 1;
}

inline Extent3D::Extent3D(const VkExtent2D& other)
{
	width = other.width;
	height = other.height;
	depth = 1;
}

} /* namespace Vulkan */

#endif /* VULKAN_STRUCTURE_VULKANEXTENT3D_H_ */
