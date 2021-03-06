/*
 * VKFrameBuffer.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKFrameBuffer.h"
#include "VKRenderPass.h"
#include "VKImage.h"
#include "VKDefine.h"

#include "../../Platform/Vulkan/VulkanFrameBuffer.h"
#include "../../Platform/Vulkan/VulkanInline.h"
#include "../../Platform/Vulkan/VulkanRenderPass.h"

#include <cassert>
#include <iostream>

namespace VK
{

FrameBuffer::FrameBuffer(RenderPass* pass):
		GHI::FrameBuffer(pass)
{
}

FrameBuffer::~FrameBuffer(void)
{
	Vulkan::Release(mFrameBuffer);
}

void FrameBuffer::Create(const GHI::FrameLayout& layout)
{
	mFrameLayout = layout;
	bool result = CheckAttachmentFormat();
	assert(true == result);
	if (true == result)
	{
		std::cout << "New FrameBuffer" << std::endl;
		CreateVulkanFrameBuffer();
	}
}

void FrameBuffer::CreateVulkanFrameBuffer(void)
{
	assert(mFrameLayout.IsValid());

	GHI::Image* attachment = mFrameLayout.GetImage(0);
	const GHI::ImageLayout& layout = attachment->GetLayout();
	const Math::Extent3Di& extent = layout.GetExtent();

	std::cout << "Width:" << extent.width << std::endl;
	std::cout << "Height:" << extent.height << std::endl;

	VkExtent2D vulkan_extent =
	{
			static_cast<uint32_t>(extent.width),
			static_cast<uint32_t>(extent.height)
	};

	std::vector<Vulkan::Image*> attachments;
	const size_t count = mFrameLayout.GetImageCount();
	attachments.reserve(count + 1);
	for (size_t index = 0; index < count; ++index)
	{
		attachment = mFrameLayout.GetImage(index);
		Image* vk_image = static_cast<Image*>(attachment);
		auto vulkan_image = vk_image->GetVulkanImage();
		attachments.push_back(vulkan_image);
	}

	auto depth_stencil = mFrameLayout.GetDepthStencil();
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

bool FrameBuffer::CheckAttachmentFormat(void)
{
	GHI::Image* depth_stencil = mFrameLayout.GetDepthStencil();
	if (nullptr != depth_stencil)
	{
		const GHI::ImageLayout& layout = depth_stencil->GetLayout();
		GHI::Format attach_format = layout.GetFormat();
		GHI::Format pass_format = mPass->GetDepthStencilFormat();
		if (attach_format != pass_format)
		{
			return false;
		}
	}

	size_t count = mFrameLayout.GetImageCount();
	if (count != mPass->GetAttachmentFormatCount())
	{
		return false;
	}
	else
	{
		for (size_t index = 0; index < count; ++index)
		{
			GHI::Image* image = mFrameLayout.GetImage(index);
			const GHI::ImageLayout& layout = image->GetLayout();
			GHI::Format attach_format = layout.GetFormat();
			GHI::Format pass_format = mPass->GetAttachmentFormat(index);
			if (attach_format != pass_format)
			{
				return false;
			}
		}
	}
	return true;
}

} /* namespace VK */
