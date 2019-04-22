/*
 * VKRenderPass.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKRenderPass.h"
#include "VKFrameBuffer.h"
#include "VKFormat.h"
#include "VKDevice.h"

#include "VulkanRenderPass.h"
#include "VulkanInline.h"
#include "VulkanImage.h"

#include <cassert>

namespace VK
{

RenderPass::RenderPass(Device* device):
		GHI::RenderPass(device)
{
}

RenderPass::~RenderPass(void)
{
	Vulkan::Release(mRenderPass);
}

void RenderPass::Create(void)
{
	assert(mFormats.size() > 0);

	VkSubpassDescription subpass_description = {};
	subpass_description.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;

	std::vector<VkAttachmentReference> attachment_references;
	std::vector<VkAttachmentDescription> attachment_descriptions;

	for (auto format : mFormats)
	{
		VkFormat vulkan_format = ConvertFormat(format);

		VkAttachmentReference reference = Vulkan::Image::GetReference(vulkan_format);
		reference.attachment = attachment_references.size();
		attachment_references.push_back(reference);

		VkAttachmentDescription description = Vulkan::Image::GetDescription(vulkan_format);
		attachment_descriptions.push_back(description);
	}

	subpass_description.colorAttachmentCount = attachment_references.size();
	subpass_description.pColorAttachments = attachment_references.data();

	VkAttachmentReference depth_reference = {};

	if (mDepthStencil != GHI::Format::FORMAT_UNDEFINED)
	{
		VkFormat depth_stencil = ConvertFormat(mDepthStencil);

		VkAttachmentDescription description = Vulkan::Image::GetDescription(depth_stencil);
		attachment_descriptions.push_back(description);

		depth_reference = Vulkan::Image::GetReference(depth_stencil);
		depth_reference.attachment = attachment_references.size();
		subpass_description.pDepthStencilAttachment = &depth_reference;
	}

	std::vector<VkSubpassDependency> subpass_dependencies =
	{
			Vulkan::RenderPass::SubpassDenpendency(VK_SUBPASS_EXTERNAL, 0),
			Vulkan::RenderPass::SubpassDenpendency(0, VK_SUBPASS_EXTERNAL)
	};

	VkRenderPassCreateInfo renderpass_create_info = Vulkan::RenderPass::CreateInfo();
	renderpass_create_info.attachmentCount = attachment_descriptions.size();
	renderpass_create_info.pAttachments = attachment_descriptions.data();
	renderpass_create_info.subpassCount = 1;
	renderpass_create_info.pSubpasses = &subpass_description;
	renderpass_create_info.dependencyCount = subpass_dependencies.size();
	renderpass_create_info.pDependencies = subpass_dependencies.data();

	auto device = static_cast<Device*>(mDevice)->GetVulkanDevice();
	mRenderPass = Vulkan::RenderPass::New(device);
	mRenderPass->Create(&renderpass_create_info);
}

GHI::FrameBuffer* RenderPass::CreateFrameBuffer(void)
{
	FrameBuffer* frame_buffer = new FrameBuffer(this);
	mFrameBuffers.push_back(frame_buffer);
	return frame_buffer;
}

} /* namespace VK */
