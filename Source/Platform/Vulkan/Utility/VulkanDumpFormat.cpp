/*
 * VulkanFormat.cpp
 *
 *  Created on: Jan 8, 2019
 *      Author: rookyma
 */

#include "VulkanDumpFormat.h"
#include "../VulkanPhysicalDevice.h"
#include "../VulkanFormat.h"
#include <cassert>

namespace Vulkan
{

void PrintFormatProperties(const VkFormatProperties& properties)
{
	struct
	{
		const char *name;
		VkFlags flags;
	} features[3];

	features[0].name = "linearTiling   FormatFeatureFlags";
	features[0].flags = properties.linearTilingFeatures;
	features[1].name = "optimalTiling  FormatFeatureFlags";
	features[1].flags = properties.optimalTilingFeatures;
	features[2].name = "bufferFeatures FormatFeatureFlags";
	features[2].flags = properties.bufferFeatures;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
	for (uint32_t i = 0; i < ARRAY_SIZE(features); ++i)
	{
		printf("\n\t%s:", features[i].name);
		if (features[i].flags == 0)
		{
			printf("\n\t\tNone");
		}
		else
		{
			printf("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
					((features[i].flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT)                  ? "\n\t\tVK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT"                  : ""),
					((features[i].flags & VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT)                  ? "\n\t\tVK_FORMAT_FEATURE_STORAGE_IMAGE_BIT"                  : ""),
					((features[i].flags & VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT)           ? "\n\t\tVK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT"           : ""),
					((features[i].flags & VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT)           ? "\n\t\tVK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT"           : ""),
					((features[i].flags & VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT)           ? "\n\t\tVK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT"           : ""),
					((features[i].flags & VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT)    ? "\n\t\tVK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT"    : ""),
					((features[i].flags & VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT)                  ? "\n\t\tVK_FORMAT_FEATURE_VERTEX_BUFFER_BIT"                  : ""),
					((features[i].flags & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT)               ? "\n\t\tVK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT"               : ""),
					((features[i].flags & VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT)         ? "\n\t\tVK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT"         : ""),
					((features[i].flags & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT)       ? "\n\t\tVK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT"       : ""),
					((features[i].flags & VK_FORMAT_FEATURE_BLIT_SRC_BIT)                       ? "\n\t\tVK_FORMAT_FEATURE_BLIT_SRC_BIT"                       : ""),
					((features[i].flags & VK_FORMAT_FEATURE_BLIT_DST_BIT)                       ? "\n\t\tVK_FORMAT_FEATURE_BLIT_DST_BIT"                       : ""),
					((features[i].flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT)    ? "\n\t\tVK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT"    : ""),
					((features[i].flags & VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG) ? "\n\t\tVK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG" : ""),
					((features[i].flags & VK_FORMAT_FEATURE_TRANSFER_SRC_BIT_KHR)               ? "\n\t\tVK_FORMAT_FEATURE_TRANSFER_SRC_BIT_KHR"               : ""),
					((features[i].flags & VK_FORMAT_FEATURE_TRANSFER_DST_BIT_KHR)               ? "\n\t\tVK_FORMAT_FEATURE_TRANSFER_DST_BIT_KHR"               : ""));
		}
	}
#undef ARRAY_SIZE
}

void DumpFormatsProperties(const PhysicalDevice* device)
{
	assert(device != nullptr);
	for (uint32_t f = 0; f < VK_FORMAT_RANGE_SIZE; ++f)
	{
		VkFormat format = static_cast<VkFormat>(f);
		printf("\nFORMAT_%s:", Vulkan::Format::GetFormatString(format));
		VkFormatProperties property = device->GetFormatProperties(format);
		PrintFormatProperties(property);
	}
}

}
