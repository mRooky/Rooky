/*
 * VkDefine.h
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKDEFINE_H_
#define SOURCE_RENDER_VK_VKDEFINE_H_

#include "VulkanClasses.h"
#include "RenderTypes.h"

namespace VK
{

	static Render::BufferUsageFlags RenderBufferUsages[] =
	{
			Render::BufferUsageFlags::BUFFER_USAGE_INDEX,
			Render::BufferUsageFlags::BUFFER_USAGE_VERTEX,
			Render::BufferUsageFlags::BUFFER_USAGE_UNIFORM,
			Render::BufferUsageFlags::BUFFER_USAGE_STORAGE,
			Render::BufferUsageFlags::BUFFER_USAGE_INDIRECT,
			Render::BufferUsageFlags::BUFFER_USAGE_UNIFORM_TEXEL,
			Render::BufferUsageFlags::BUFFER_USAGE_STORAGE_TEXEL
	};

	static VkBufferUsageFlags VulkanBufferUsages[] =
	{
			VK_BUFFER_USAGE_INDEX_BUFFER_BIT,
			VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
			VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
			VK_BUFFER_USAGE_STORAGE_BUFFER_BIT,
			VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT,
			VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT,
			VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT
	};

	static Render::ImageUsageFlags RenderImageUsages[] =
	{
			Render::ImageUsageFlags::IMAGE_USAGE_SAMPLED,
			Render::ImageUsageFlags::IMAGE_USAGE_STORAGE,
			Render::ImageUsageFlags::IMAGE_USAGE_COLOR_ATTACHMENT,
			Render::ImageUsageFlags::IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT,
			Render::ImageUsageFlags::IMAGE_USAGE_TRANSIENT_ATTACHMENT,
			Render::ImageUsageFlags::IMAGE_USAGE_INPUT_ATTACHMENT
	};

	static VkImageUsageFlags VulkanImageUsages[] =
	{
			VK_IMAGE_USAGE_SAMPLED_BIT,
			VK_IMAGE_USAGE_STORAGE_BIT,
			VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
			VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
			VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT,
			VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT
	};

}

#endif /* SOURCE_RENDER_VK_VKDEFINE_H_ */
