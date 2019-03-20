/*
 * VKFrameBuffer.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKFrameBuffer.h"
#include "VKRenderPass.h"
#include "VKContext.h"
#include "VKImage.h"

#include "VulkanFrameBuffer.h"
#include "VulkanInline.h"
#include "VulkanRenderPass.h"

#include <cassert>

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

void FrameBuffer::Create(const Render::Extent2D& extent)
{
	assert(mAttachments.size() > 0);

	VkExtent2D vulkan_extent = {};
	vulkan_extent.width = static_cast<uint32_t>(extent.width);
	vulkan_extent.height = static_cast<uint32_t>(extent.height);

	std::vector<Vulkan::Image*> attachments;
	attachments.reserve(mAttachments.size());
	for (auto attachment : mAttachments)
	{
		Image* image = static_cast<Image*>(attachment);
		auto vulkan_image = image->GetVulkanImage();
		attachments.push_back(vulkan_image);
	}

	if (mDepthStencil != nullptr)
	{
		Image* image = static_cast<Image*>(mDepthStencil);
		auto vulkan_image = image->GetVulkanImage();
		attachments.push_back(vulkan_image);
	}

	RenderPass* pass = static_cast<RenderPass*>(mPass);
	auto vulkan_pass = pass->GetVulkanRenderPass();
	mFrameBuffer = Vulkan::FrameBuffer::New(vulkan_pass->GetDevice());
	mFrameBuffer->Create(vulkan_pass, attachments, vulkan_extent);
}

} /* namespace VK */
