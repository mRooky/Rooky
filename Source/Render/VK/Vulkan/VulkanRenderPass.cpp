/*
 * VulkanRenderPass.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanRenderPass.h"
#include "VulkanDevice.h"
#include <cassert>

namespace Vulkan
{

RenderPass::RenderPass(Device* device) :
		DeviceObject(device)
{
}

RenderPass::~RenderPass(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyRenderPass(device, m_pass, nullptr);
	m_pass = VK_NULL_HANDLE;
}

VkResult RenderPass::Create(const VkRenderPassCreateInfo* info)
{
	mResult = vkCreateRenderPass(mDevice->GetHandle(), info, nullptr, &m_pass);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

VkAttachmentDescription RenderPass::AttachmentDescription(void)
{
	VkAttachmentDescription attachment_description = {};
	attachment_description.format = VK_FORMAT_UNDEFINED;
	attachment_description.samples = VK_SAMPLE_COUNT_FLAG_BITS_MAX_ENUM;
	attachment_description.loadOp = VK_ATTACHMENT_LOAD_OP_MAX_ENUM;
	attachment_description.storeOp = VK_ATTACHMENT_STORE_OP_MAX_ENUM;
	attachment_description.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_MAX_ENUM;
	attachment_description.stencilStoreOp = VK_ATTACHMENT_STORE_OP_MAX_ENUM;
	attachment_description.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
	attachment_description.finalLayout = VK_IMAGE_LAYOUT_MAX_ENUM;
	attachment_description.flags = 0;
	return attachment_description;
}

VkSubpassDescription RenderPass::SubpassDescription(void)
{
	VkSubpassDescription subpass_description = {};
	subpass_description.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
	subpass_description.flags = 0;
	subpass_description.inputAttachmentCount = 0;
	subpass_description.pInputAttachments = nullptr;
	subpass_description.colorAttachmentCount = 0;
	subpass_description.pColorAttachments = nullptr;
	subpass_description.preserveAttachmentCount = 0;
	subpass_description.pResolveAttachments = nullptr;
	subpass_description.pDepthStencilAttachment = nullptr;
	subpass_description.pPreserveAttachments = nullptr;
	return subpass_description;
}

VkSubpassDependency RenderPass::SubpassDenpendency(uint32_t from, uint32_t to)
{
	VkSubpassDependency sub_pass_dependency = {};
	sub_pass_dependency.srcSubpass = from; //VK_SUBPASS_EXTERNAL;
	sub_pass_dependency.dstSubpass = to; //0;

	if (from == VK_SUBPASS_EXTERNAL && to == 0)
	{
		sub_pass_dependency.srcStageMask = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
		sub_pass_dependency.dstStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		sub_pass_dependency.srcAccessMask = VK_ACCESS_MEMORY_READ_BIT;
		sub_pass_dependency.dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
		sub_pass_dependency.dependencyFlags = VK_DEPENDENCY_BY_REGION_BIT;
	}
	else
	{
		sub_pass_dependency.srcStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		sub_pass_dependency.dstStageMask = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
		sub_pass_dependency.srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
		sub_pass_dependency.dstAccessMask = VK_ACCESS_MEMORY_READ_BIT;
		sub_pass_dependency.dependencyFlags = VK_DEPENDENCY_BY_REGION_BIT;
	}
	return sub_pass_dependency;
}

VkRenderPassCreateInfo RenderPass::CreateInfo(void)
{
	VkRenderPassCreateInfo render_pass_create_info = {};
	render_pass_create_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
	render_pass_create_info.attachmentCount = 0;
	render_pass_create_info.subpassCount = 0;
	render_pass_create_info.pSubpasses = nullptr;
	render_pass_create_info.pAttachments = nullptr;
	return render_pass_create_info;
}

VkRenderPassBeginInfo RenderPass::BeginInfo(void)
{
	VkRenderPassBeginInfo render_pass_begin_info = {};
	render_pass_begin_info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
	render_pass_begin_info.framebuffer = VK_NULL_HANDLE;
	render_pass_begin_info.renderArea.extent.width = 0;
	render_pass_begin_info.renderArea.extent.height = 0;
	render_pass_begin_info.renderPass = VK_NULL_HANDLE;
	render_pass_begin_info.pClearValues = nullptr;
	render_pass_begin_info.clearValueCount = 0;
	render_pass_begin_info.renderArea.offset.x = 0;
	render_pass_begin_info.renderArea.offset.y = 0;
	return render_pass_begin_info;
}

} /* namespace Vulkan */
