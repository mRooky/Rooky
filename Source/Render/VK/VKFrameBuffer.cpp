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

void FrameBuffer::Create(const std::vector<Render::Image*>& attachments, Render::Image* depth)
{
	size_t size = attachments.size();
	assert(size > 0);
	mAttachments.resize(size);
	assert(mAttachments.size() >= size);
	std::copy(attachments.begin(), attachments.end(), mAttachments.begin());
	mDepthStencil = depth;
	std::cout << "New FrameBuffer" << std::endl;
	CreateVulkanFrameBuffer();
}

void FrameBuffer::CreateVulkanFrameBuffer(void)
{
	assert(mAttachments.size() > 0);

	auto attachment = mAttachments.at(0);
	auto& layout = attachment->GetLayout();
	auto& extent = layout.extent;

	std::cout << "Width:" << extent.width << " Height:" << extent.height << std::endl;

	VkExtent2D vulkan_extent = {};
	vulkan_extent.width = static_cast<uint32_t>(extent.width);
	vulkan_extent.height = static_cast<uint32_t>(extent.height);

	std::vector<Vulkan::Image*> attachments;
	attachments.reserve(mAttachments.size() + 1);
	for (auto attachment : mAttachments)
	{
		Image* vk_image = static_cast<Image*>(attachment);
		auto vulkan_image = vk_image->GetVulkanImage();
		attachments.push_back(vulkan_image);
	}

	if (mDepthStencil != nullptr)
	{
		Image* vk_image = static_cast<Image*>(mDepthStencil);
		auto vulkan_image = vk_image->GetVulkanImage();
		attachments.push_back(vulkan_image);
	}

	RenderPass* pass = static_cast<RenderPass*>(mPass);
	auto vulkan_pass = pass->GetVulkanRenderPass();
	mFrameBuffer = Vulkan::FrameBuffer::New(vulkan_pass->GetDevice());
	mFrameBuffer->Create(vulkan_pass, attachments, vulkan_extent);
}

} /* namespace VK */
