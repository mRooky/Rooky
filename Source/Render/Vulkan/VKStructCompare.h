/*
 * VulkanStructCompare.h
 *
 *  Created on: Feb 27, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKSTRUCTCOMPARE_H_
#define SOURCE_RENDER_VK_VKSTRUCTCOMPARE_H_

#include <vulkan/vulkan.h>

namespace VK
{
	static inline bool operator==(const VkDescriptorImageInfo& v1, const VkDescriptorImageInfo& v2)
	{
		bool equal = v1.sampler == v2.sampler;
		equal = equal && (v1.imageView == v2.imageView);
		equal = equal && (v1.imageLayout == v2.imageLayout);
		return equal;
	}

	static inline bool operator==(const VkDescriptorBufferInfo& v1, const VkDescriptorBufferInfo& v2)
	{
		bool equal = v1.buffer == v2.buffer;
		equal = equal && v1.offset == v2.offset;
		equal = equal && v1.range == v2.range;
		return equal;
	}

	static inline bool operator==(const VkDescriptorSetLayoutBinding& v1, const VkDescriptorSetLayoutBinding& v2)
	{
		bool equal = v1.binding == v2.binding;
		equal = equal && (v1.descriptorType == v2.descriptorType);
		equal = equal && (v1.descriptorCount == v2.descriptorCount);
		equal = equal && (v1.stageFlags == v2.stageFlags);
		return equal;
	}
}

#endif /* SOURCE_RENDER_VK_VKSTRUCTCOMPARE_H_ */
