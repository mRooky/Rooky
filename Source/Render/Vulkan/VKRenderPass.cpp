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
	mRenderpassCreateInfo = Vulkan::RenderPass::CreateInfo();
}

RenderPass::~RenderPass(void)
{
	Vulkan::Release(mRenderPass);
}

void RenderPass::Create(size_t count)
{
	assert(mFormats.size() > 0);
	CreateReference();
	CreateDescription();
	CreateSubDependency(count);
	CreateSubDescription(count);

	mRenderpassCreateInfo.attachmentCount = mDescriptions.size();
	mRenderpassCreateInfo.pAttachments = mDescriptions.data();
	mRenderpassCreateInfo.subpassCount = mSubDescriptions.size();
	mRenderpassCreateInfo.pSubpasses = mSubDescriptions.data();
	mRenderpassCreateInfo.dependencyCount = mSubDependencies.size();
	mRenderpassCreateInfo.pDependencies = mSubDependencies.data();

	auto device = static_cast<Device*>(mDevice)->GetVulkanDevice();
	mRenderPass = Vulkan::RenderPass::New(device);
	mRenderPass->Create(&mRenderpassCreateInfo);
}

void RenderPass::CreateReference(void)
{
	for (auto format : mFormats)
	{
		VkFormat vulkan_format = ConvertFormat(format);

		VkAttachmentReference reference = Vulkan::Image::GetReference(vulkan_format);
		reference.attachment = mReferences.size();
		mReferences.push_back(reference);
	}

	if (mDepthStencil != GHI::Format::FORMAT_UNDEFINED)
	{
		VkFormat depth_stencil = ConvertFormat(mDepthStencil);
		mDepthReference = Vulkan::Image::GetReference(depth_stencil);
		mDepthReference.attachment = mReferences.size();
	}

	assert(mReferences.size() > 0);
}

void RenderPass::CreateDescription(void)
{
	for (auto format : mFormats)
	{
		VkFormat vulkan_format = ConvertFormat(format);
		VkAttachmentDescription description = Vulkan::Image::GetDescription(vulkan_format);
		mDescriptions.push_back(description);
	}

	if (mDepthStencil != GHI::Format::FORMAT_UNDEFINED)
	{
		VkFormat depth_stencil = ConvertFormat(mDepthStencil);

		VkAttachmentDescription description = Vulkan::Image::GetDescription(depth_stencil);
		mDescriptions.push_back(description);
	}

	assert(mDescriptions.size() > 0);
}

void RenderPass::CreateSubDependency(size_t count)
{
	assert(count == 1); // Delete Future
	VkSubpassDependency dependency = {};
	dependency = Vulkan::RenderPass::SubpassDenpendency(VK_SUBPASS_EXTERNAL, 0);
	mSubDependencies.push_back(dependency);

	for (size_t index = 1; index < count; ++index)
	{
		dependency = Vulkan::RenderPass::SubpassDenpendency(index - 1, index);
	}

	dependency = Vulkan::RenderPass::SubpassDenpendency(count - 1, VK_SUBPASS_EXTERNAL);
	mSubDependencies.push_back(dependency);
	assert(mSubDependencies.size() > 0);
}

void RenderPass::CreateSubDescription(size_t count)
{
	assert(count == 1); // Delete Future
	VkSubpassDescription description = {};
	description.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
	for (size_t index = 0; index < count; ++index)
	{
		description.colorAttachmentCount = mReferences.size();
		description.pColorAttachments = mReferences.data();

		if (mDepthStencil != GHI::Format::FORMAT_UNDEFINED)
		{
			//assert(mDepthReference.layout != ?);
			description.pDepthStencilAttachment = &mDepthReference;
		}

		mSubDescriptions.push_back(description);
	}

	assert(mSubDescriptions.size() > 0);
}

GHI::FrameBuffer* RenderPass::CreateFrameBuffer(void)
{
	FrameBuffer* frame_buffer = new FrameBuffer(this);
	mFrameBuffers.push_back(frame_buffer);
	return frame_buffer;
}

} /* namespace VK */
