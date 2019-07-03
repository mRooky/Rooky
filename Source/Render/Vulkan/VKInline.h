/*
 * VKInline.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKINLINE_H_
#define SOURCE_RENDER_VK_VKINLINE_H_

#include "VKDefine.h"
#include "../../Core/GHI/GHIResourceUsage.h"

#include <vulkan/vulkan.h>
#include <cassert>

namespace VK
{

static inline void NotImplemented(void)
{
	assert(false);
}

static inline GHI::ResourceUsage CreateStageBufferUsageType(void)
{
	GHI::ResourceUsage usage = {};
	usage.memoryUsage.cpuAccess = TRUE;
	usage.memoryUsage.read = TRUE;
	usage.memoryUsage.write = TRUE;
	return usage;
}

static inline VkMemoryPropertyFlags GetMemoryPropertyFlags(GHI::ResourceUsage& usage)
{
	if (usage.memoryUsage.cpuAccess == 1)
	{
		return VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
	}
	else
	{
		return VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
	}
}

static inline VkBufferUsageFlags ConvertBufferUsageFlags(const GHI::ResourceUsage& usage)
{
	VkBufferUsageFlags flags = 0;
	flags |= (usage.memoryUsage.read == TRUE) ? VK_BUFFER_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (usage.memoryUsage.write == TRUE) ? VK_BUFFER_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (usage.bufferUsage.indexBuffer == TRUE) ? VK_BUFFER_USAGE_INDEX_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.vertexBuffer == TRUE) ? VK_BUFFER_USAGE_VERTEX_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.uniformBuffer == TRUE) ? VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.storageBuffer == TRUE) ? VK_BUFFER_USAGE_STORAGE_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.indirectBuffer == TRUE) ? VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT : 0;
	return flags;
}

static inline VkImageUsageFlags ConvertImageUsageFlags(const GHI::ResourceUsage& usage)
{
	VkImageUsageFlags flags = 0;
	flags |= (usage.memoryUsage.read == TRUE) ? VK_IMAGE_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (usage.memoryUsage.write == TRUE) ? VK_IMAGE_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (usage.imageUsage.sampledImage == TRUE) ? VK_IMAGE_USAGE_SAMPLED_BIT : 0;
	flags |= (usage.imageUsage.storageImage == TRUE) ? VK_IMAGE_USAGE_STORAGE_BIT : 0;
	flags |= (usage.imageUsage.colorImage == TRUE) ? VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT : 0;
	flags |= (usage.imageUsage.depthStencil == TRUE) ? VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT : 0;
	flags |= (usage.imageUsage.transientImage == TRUE) ? VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT : 0;
	flags |= (usage.imageUsage.inputImage == TRUE) ? VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT : 0;
	return flags;
}

static inline GHI::ResourceUsage ConvertBufferUsageFlags(VkBufferUsageFlags flags)
{
	GHI::ResourceUsage resource_usage = {};
	resource_usage.memoryUsage.read = (flags & VK_BUFFER_USAGE_TRANSFER_SRC_BIT) ? 1 : 0;
	resource_usage.memoryUsage.write = (flags & VK_BUFFER_USAGE_TRANSFER_DST_BIT) ? 1 : 0;
	resource_usage.bufferUsage.indexBuffer = (flags & VK_BUFFER_USAGE_INDEX_BUFFER_BIT) ? 1 : 0;
	resource_usage.bufferUsage.vertexBuffer = (flags & VK_BUFFER_USAGE_VERTEX_BUFFER_BIT) ? 1 : 0;
	resource_usage.bufferUsage.uniformBuffer = (flags & VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT) ? 1 : 0;
	resource_usage.bufferUsage.storageBuffer = (flags & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT) ? 1 : 0;
	resource_usage.bufferUsage.indirectBuffer = (flags & VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT) ? 1 : 0;
	return resource_usage;
}

}

#endif /* SOURCE_RENDER_VK_VKINLINE_H_ */
