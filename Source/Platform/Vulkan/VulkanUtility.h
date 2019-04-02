/*
 * VulkanUtility.h
 *
 *  Created on: Sep 19, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANUTILITY_H_
#define VULKAN_VULKANUTILITY_H_

#include <vulkan/vulkan.h>

namespace Vulkan
{

bool operator == (const VkDescriptorSetLayoutBinding& a, const VkDescriptorSetLayoutBinding& b);

} /* namespace Vulkan */

#endif /* VULKAN_VULKANUTILITY_H_ */
