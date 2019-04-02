/*
 * VulkanFrameBuffer.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanFrameBuffer.h"
#include "VulkanDevice.h"
#include "VulkanRenderPass.h"
#include "VulkanImage.h"
#include "VulkanImageView.h"
#include <cassert>

namespace Vulkan
{

FrameBuffer::FrameBuffer(Device* device):
		DeviceObject(device)
{
	mAttachments.clear();
}

FrameBuffer::~FrameBuffer(void)
{
	mAttachments.clear();
	VkDevice device = mDevice->GetHandle();
	vkDestroyFramebuffer(device, m_frameBuffer, nullptr);
	m_frameBuffer = VK_NULL_HANDLE;
}

VkResult FrameBuffer::Create(const VkFramebufferCreateInfo* info)
{
	assert(m_frameBuffer == VK_NULL_HANDLE);
	mResult = vkCreateFramebuffer(mDevice->GetHandle(), info, nullptr, &m_frameBuffer);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

VkResult FrameBuffer::Create(RenderPass* parent, const std::vector<Image*>& attachments, VkExtent2D extent)
{
	assert(parent->GetResult() == VK_SUCCESS);
	m_parent = parent;
	mAttachments.reserve(attachments.size());
	std::vector<VkImageView> views;
	for (uint32_t index = 0; index < attachments.size(); ++index)
	{
		Image* attachment = attachments.at(index);
		VkImageView view = attachment->GetView()->GetHandle();
		views.push_back(view);
		mAttachments.push_back(attachment);
	}
	assert(views.size() > 0);
	VkFramebufferCreateInfo frame_buffer_create_info = FrameBuffer::CreateInfo();
	frame_buffer_create_info.renderPass = parent->GetHandle();
	frame_buffer_create_info.attachmentCount = views.size();
	frame_buffer_create_info.pAttachments = views.data();
	frame_buffer_create_info.width = extent.width;
	frame_buffer_create_info.height = extent.height;
	frame_buffer_create_info.layers = 1;

	return Create(&frame_buffer_create_info);
}

VkFramebufferCreateInfo FrameBuffer::CreateInfo(void)
{
	VkFramebufferCreateInfo frame_buffer_create_info = {};
	frame_buffer_create_info.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
	frame_buffer_create_info.pNext = nullptr;
	frame_buffer_create_info.flags = 0;
	frame_buffer_create_info.renderPass = VK_NULL_HANDLE;
	frame_buffer_create_info.attachmentCount = 0;
	frame_buffer_create_info.pAttachments = nullptr;
	frame_buffer_create_info.width = 0;
	frame_buffer_create_info.height = 0;
	frame_buffer_create_info.layers = 0;
	return frame_buffer_create_info;
}


} /* namespace Vulkan */
