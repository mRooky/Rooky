/*
 * VKFrameBuffer.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKFrameBuffer.h"
#include "VKRenderPass.h"
#include "VKImage.h"

#include "VulkanFrameBuffer.h"
#include "VulkanInline.h"
#include "VulkanRenderPass.h"

#include <cassert>
#include <iostream>

namespace VK
{

FrameBuffer::FrameBuffer(RenderPass* pass):
		Render::FrameBuffer(pass)
{
}

FrameBuffer::~FrameBuffer(void)
{
	Vulkan::Release(mFrameBuffer);
}

void FrameBuffer::Create(const Render::Attachment& attachment)
{
	mAttachment = attachment;
	std::cout << "New FrameBuffer" << std::endl;
	CreateVulkanFrameBuffer();
}

void FrameBuffer::CreateVulkanFrameBuffer(void)
{
	assert(mAttachment.IsValid());

	auto attachment = mAttachment.GetImage(0);
	auto& layout = attachment->GetLayout();
	auto& extent = layout.extent;

	std::cout << "Width:" << extent.width << std::endl;
	std::cout << "Height:" << extent.height << std::endl;

	VkExtent2D vulkan_extent =
	{
			static_cast<uint32_t>(extent.width),
			static_cast<uint32_t>(extent.height)
	};

	std::vector<Vulkan::Image*> attachments;
	const size_t count = mAttachment.GetImageCount();
	attachments.reserve(count + 1);
	for (size_t index = 0; index < count; ++index)
	{
		attachment = mAttachment.GetImage(index);
		Image* vk_image = static_cast<Image*>(attachment);
		auto vulkan_image = vk_image->GetVulkanImage();
		attachments.push_back(vulkan_image);
	}

	auto depth_stencil = mAttachment.GetDepthStencil();
	if (depth_stencil != nullptr)
	{
		Image* vk_image = static_cast<Image*>(depth_stencil);
		auto vulkan_image = vk_image->GetVulkanImage();
		attachments.push_back(vulkan_image);
	}

	RenderPass* vk_pass = static_cast<RenderPass*>(mPass);
	auto vulkan_pass = vk_pass->GetVulkanRenderPass();
	mFrameBuffer = Vulkan::FrameBuffer::New(vulkan_pass->GetDevice());
	mFrameBuffer->Create(vulkan_pass, attachments, vulkan_extent);
}

} /* namespace VK */
