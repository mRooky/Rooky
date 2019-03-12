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

static inline VkMemoryPropertyFlags GetMemoryPropertyFlags(Render::ResourceHeap heap)
{
	return (heap.CPUAccess == 1) ? VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT : VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
}

static inline VkBufferUsageFlags ConvertBufferUsageFlag(const Render::ResourceUsage& usage)
{
	assert(usage.heap.Buffer == 1);
	VkBufferUsageFlags flags = 0;
	if (usage.binding.IndexBuffer == 1)
	{
		flags |= VK_BUFFER_USAGE_INDEX_BUFFER_BIT;
	}

	if (usage.binding.VertexBuffer == 1)
	{
		flags |= VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
	}

	if (usage.binding.UniformBuffer == 1)
	{
		flags |= VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;
	}

	if (usage.binding.StorageBuffer == 1)
	{
		flags |= VK_BUFFER_USAGE_STORAGE_BUFFER_BIT;
	}

	if (usage.binding.IndirectBuffer == 1)
	{
		flags |= VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT;
	}
	return flags;
}

static inline VkImageUsageFlags ConvertImageUsageFlag(const Render::ResourceUsage&  usage)
{
	assert(usage.heap.Image == 1);
	VkImageUsageFlags flags = 0;
	if (usage.binding.SampledImage == 1)
	{
		flags |= VK_IMAGE_USAGE_SAMPLED_BIT;
	}

	if (usage.binding.StorageImage == 1)
	{
		flags |= VK_IMAGE_USAGE_STORAGE_BIT;
	}

	if (usage.binding.ColorImage == 1)
	{
		flags |= VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
	}

	if (usage.binding.DepthStencil == 1)
	{
		flags |= VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;
	}

	if (usage.binding.TransientImage == 1)
	{
		flags |= VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT;
	}

	if (usage.binding.InputImage == 1)
	{
		flags |= VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT;
	}

	return flags;
}

}

#endif /* SOURCE_RENDER_VK_VKINLINE_H_ */
