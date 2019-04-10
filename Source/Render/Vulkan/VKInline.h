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

static inline VkMemoryPropertyFlags GetMemoryPropertyFlags(Render::AllocateType allocate)
{
	if (allocate.CPUAccess == 1)
	{
		return VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
	}
	else
	{
		return VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
	}
}

static inline VkBufferUsageFlags ConvertBufferUsageFlags(const Render::ResourceUsage& usage)
{
	assert(usage.type == Render::ResourceType::RESOURCE_TYPE_BUFFER);
	VkBufferUsageFlags flags = 0;
	flags |= (usage.allocate.Source == 1) ? VK_BUFFER_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (usage.allocate.Destination == 1) ? VK_BUFFER_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (usage.bufferUsage.IndexBuffer == 1) ? VK_BUFFER_USAGE_INDEX_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.VertexBuffer == 1) ? VK_BUFFER_USAGE_VERTEX_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.UniformBuffer == 1) ? VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.StorageBuffer == 1) ? VK_BUFFER_USAGE_STORAGE_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.IndirectBuffer == 1) ? VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT : 0;
	return flags;
}

static inline VkImageUsageFlags ConvertImageUsageFlags(const Render::ResourceUsage&  usage)
{
	assert(usage.type == Render::ResourceType::RESOURCE_TYPE_IMAGE);
	VkImageUsageFlags flags = 0;
	flags |= (usage.allocate.Source == 1) ? VK_IMAGE_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (usage.allocate.Destination == 1) ? VK_IMAGE_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (usage.imageUsage.SampledImage == 1) ? VK_IMAGE_USAGE_SAMPLED_BIT : 0;
	flags |= (usage.imageUsage.StorageImage == 1) ? VK_IMAGE_USAGE_STORAGE_BIT : 0;
	flags |= (usage.imageUsage.ColorImage == 1) ? VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT : 0;
	flags |= (usage.imageUsage.DepthStencil == 1) ? VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT : 0;
	flags |= (usage.imageUsage.TransientImage == 1) ? VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT : 0;
	flags |= (usage.imageUsage.InputImage == 1) ? VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT : 0;
	return flags;
}

static inline Render::ResourceUsage ConvertBufferUsageFlags(VkBufferUsageFlags flags)
{
	Render::ResourceUsage resource_usage = Render::ResourceUsage::GetBufferUsage(false);
	resource_usage.allocate.Source = (flags & VK_BUFFER_USAGE_TRANSFER_SRC_BIT) ? 1 : 0;
	resource_usage.allocate.Destination = (flags & VK_BUFFER_USAGE_TRANSFER_DST_BIT) ? 1 : 0;
	resource_usage.bufferUsage.IndexBuffer = (flags & VK_BUFFER_USAGE_INDEX_BUFFER_BIT) ? 1 : 0;
	resource_usage.bufferUsage.VertexBuffer = (flags & VK_BUFFER_USAGE_VERTEX_BUFFER_BIT) ? 1 : 0;
	resource_usage.bufferUsage.UniformBuffer = (flags & VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT) ? 1 : 0;
	resource_usage.bufferUsage.StorageBuffer = (flags & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT) ? 1 : 0;
	resource_usage.bufferUsage.IndirectBuffer = (flags & VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT) ? 1 : 0;
	return resource_usage;
}

}

#endif /* SOURCE_RENDER_VK_VKINLINE_H_ */
