/*
 * VulkanUtility.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: rookyma
 */

#include <VulkanUtility.h>

namespace Vulkan
{

bool operator ==(const VkDescriptorSetLayoutBinding& a, const VkDescriptorSetLayoutBinding& b)
{
	return a.binding == b.binding
			&& a.descriptorType == b.descriptorType
			&& a.descriptorCount == b.descriptorCount
			&& a.stageFlags == b.stageFlags
			&& a.pImmutableSamplers == b.pImmutableSamplers;
}

} /* namespace Vulkan */
