/*
 * VKInline.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKINLINE_H_
#define SOURCE_RENDER_VK_VKINLINE_H_

#include "VKDefine.h"
#include <cassert>

namespace VK
{

static inline void NotImplemented(void)
{
	assert(false);
}

static inline GHI::UsageType CreateStageBufferUsageType(void)
{
	GHI::UsageType stage_usage_type = {};
	stage_usage_type.cpuAccess = TRUE;
	stage_usage_type.source = TRUE;
	stage_usage_type.destination = TRUE;
	stage_usage_type.type = GHI::ResourceType::BUFFER;
	return stage_usage_type;
}

static inline VkMemoryPropertyFlags GetMemoryPropertyFlags(GHI::UsageType usage)
{
	if (usage.cpuAccess == 1)
	{
		return VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
	}
	else
	{
		return VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
	}
}

static inline VkBufferUsageFlags ConvertBufferUsageFlags(const GHI::UsageType& usage)
{
	assert(usage.type == GHI::ResourceType::BUFFER);
	VkBufferUsageFlags flags = 0;
	flags |= (usage.source == TRUE) ? VK_BUFFER_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (usage.destination == TRUE) ? VK_BUFFER_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (usage.indexBuffer == TRUE) ? VK_BUFFER_USAGE_INDEX_BUFFER_BIT : 0;
	flags |= (usage.vertexBuffer == TRUE) ? VK_BUFFER_USAGE_VERTEX_BUFFER_BIT : 0;
	flags |= (usage.uniformBuffer == TRUE) ? VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT : 0;
	flags |= (usage.storageBuffer == TRUE) ? VK_BUFFER_USAGE_STORAGE_BUFFER_BIT : 0;
	flags |= (usage.indirectBuffer == TRUE) ? VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT : 0;
	return flags;
}

static inline VkImageUsageFlags ConvertImageUsageFlags(const GHI::UsageType&  usage)
{
	assert(usage.type == GHI::ResourceType::IMAGE);
	VkImageUsageFlags flags = 0;
	flags |= (usage.source == TRUE) ? VK_IMAGE_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (usage.destination == TRUE) ? VK_IMAGE_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (usage.sampledImage == TRUE) ? VK_IMAGE_USAGE_SAMPLED_BIT : 0;
	flags |= (usage.storageImage == TRUE) ? VK_IMAGE_USAGE_STORAGE_BIT : 0;
	flags |= (usage.colorImage == TRUE) ? VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT : 0;
	flags |= (usage.depthStencil == TRUE) ? VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT : 0;
	flags |= (usage.transientImage == TRUE) ? VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT : 0;
	flags |= (usage.inputImage == TRUE) ? VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT : 0;
	return flags;
}

static inline GHI::UsageType ConvertBufferUsageFlags(VkBufferUsageFlags flags)
{
	GHI::UsageType resource_usage = {};
	resource_usage.type = GHI::ResourceType::BUFFER;
	resource_usage.source = (flags & VK_BUFFER_USAGE_TRANSFER_SRC_BIT) ? 1 : 0;
	resource_usage.destination = (flags & VK_BUFFER_USAGE_TRANSFER_DST_BIT) ? 1 : 0;
	resource_usage.indexBuffer = (flags & VK_BUFFER_USAGE_INDEX_BUFFER_BIT) ? 1 : 0;
	resource_usage.vertexBuffer = (flags & VK_BUFFER_USAGE_VERTEX_BUFFER_BIT) ? 1 : 0;
	resource_usage.uniformBuffer = (flags & VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT) ? 1 : 0;
	resource_usage.storageBuffer = (flags & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT) ? 1 : 0;
	resource_usage.indirectBuffer = (flags & VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT) ? 1 : 0;
	return resource_usage;
}

}

#endif /* SOURCE_RENDER_VK_VKINLINE_H_ */
