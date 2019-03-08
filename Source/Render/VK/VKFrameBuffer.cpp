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

void FrameBuffer::Create(const Render::Extent2& extent)
{
	assert(mAttachments.size() > 0);

	VkExtent2D vk_extent = {};
	vk_extent.width = static_cast<uint32_t>(extent.width);
	vk_extent.height = static_cast<uint32_t>(extent.height);

	std::vector<Vulkan::Image*> attachments;
	attachments.reserve(mAttachments.size());
	for (auto attachment : mAttachments)
	{
		Image* image = StaticCast(attachment);
		auto vk_image = image->GetImageVK();
		attachments.push_back(vk_image);
	}

	if (mDepthStencil != nullptr)
	{
		Image* image = StaticCast(mDepthStencil);
		auto vk_image = image->GetImageVK();
		attachments.push_back(vk_image);
	}

	RenderPass* pass = StaticCast(mPass);
	auto vk_pass = pass->GetRenderPassVK();
	mFrameBuffer = Vulkan::FrameBuffer::New(vk_pass->GetDevice());
	mFrameBuffer->Create(vk_pass, attachments, vk_extent);
}

} /* namespace VK */
