/*
 * VulkanExtent2D.h
 *
 *  Created on: Dec 23, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_STRUCTURE_VULKANEXTENT2D_H_
#define VULKAN_STRUCTURE_VULKANEXTENT2D_H_

#include <vulkan/vulkan.h>

namespace Vulkan
{

class Extent2D: public VkExtent2D
{
public:
	Extent2D(void);
	Extent2D(const VkExtent2D& extent);
	~Extent2D(void) = default;
};

inline Extent2D::Extent2D(void)
{
	width = 0;
	height = 0;
}

inline Extent2D::Extent2D(const VkExtent2D& extent)
{
	width = extent.width;
	height = extent.height;
}

} /* namespace Vulkan */

#endif /* VULKAN_STRUCTURE_VULKANEXTENT2D_H_ */
