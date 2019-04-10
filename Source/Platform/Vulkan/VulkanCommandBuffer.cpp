/*
 * VulkanCommandBuffer.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanCommandBuffer.h"
#include "VulkanDevice.h"
#include "VulkanCommandPool.h"
#include "VulkanBuffer.h"
#include "VulkanRenderPass.h"
#include "VulkanFrameBuffer.h"
#include "VulkanImage.h"
#include "VulkanSemaphore.h"
#include "VulkanPipeline.h"
#include "VulkanPipelineLayout.h"
#include "VulkanDescriptorSet.h"
#include "VulkanDrawCall.h"
#include "VulkanInline.h"
#include "VulkanDefine.h"
#include <cassert>

namespace Vulkan
{

CommandBuffer::CommandBuffer(Device* device):
		DeviceObject(device)
{
}

CommandBuffer::~CommandBuffer(void)
{
	Release(m_semaphore);
	VkDevice device = mDevice->GetHandle();
	VkCommandPool pool = m_pool->GetHandle();
	vkFreeCommandBuffers(device, pool, 1, &m_buffer);
}

VkResult CommandBuffer::Create(CommandPool* pool, VkCommandBufferLevel level)
{
	m_pool = pool;
	VkCommandBufferAllocateInfo command_buffer_allocate_info = CommandBuffer::AllocateInfo();
	command_buffer_allocate_info.commandPool = m_pool->GetHandle();
	command_buffer_allocate_info.level = level;
	command_buffer_allocate_info.commandBufferCount = 1;
	return Create(&command_buffer_allocate_info);
}

VkResult CommandBuffer::Create(const VkCommandBufferAllocateInfo* info)
{
	assert(info->commandBufferCount == 1);
	mResult = vkAllocateCommandBuffers(mDevice->GetHandle(), info, &m_buffer);
	assert(mResult == VK_SUCCESS);
	m_semaphore = Semaphore::New(mDevice);
	m_semaphore->Create();
	return mResult;
}

void CommandBuffer::Begin(VkCommandBufferUsageFlags flags)
{
	VkCommandBufferBeginInfo command_buffer_begin_info = CommandBuffer::BeginInfo();
	command_buffer_begin_info.flags = flags;
	vkBeginCommandBuffer(m_buffer, &command_buffer_begin_info);
	m_begin = true;
}

void CommandBuffer::End(void)
{
	mResult = vkEndCommandBuffer(m_buffer);
	VK_RESULT_CHECK(mResult, VK_SUCCESS);
	m_begin = false;
}

void CommandBuffer::BindVertexBuffers(Buffer* buffer, uint32_t binding, VkDeviceSize offset)
{
	assert(buffer->GetUsage() & VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
	VkBuffer handle = buffer->GetHandle();
	vkCmdBindVertexBuffers(m_buffer, binding, 1, &handle, &offset);
}

void CommandBuffer::BindIndexBuffer(Buffer* buffer, VkDeviceSize offset, VkIndexType type)
{
	assert(buffer->GetUsage() & VK_BUFFER_USAGE_INDEX_BUFFER_BIT);
	VkBuffer handle = buffer->GetHandle();
	vkCmdBindIndexBuffer(m_buffer, handle, offset, type);
}

void CommandBuffer::SetScissor(uint32_t first, uint32_t count, const VkRect2D* scissors)
{
	assert(count > 0);
	vkCmdSetScissor(m_buffer, first, count, scissors);
}

void CommandBuffer::SetViewport(uint32_t first, uint32_t count, const VkViewport* viewports)
{
	assert(count > 0);
	vkCmdSetViewport(m_buffer, first, count, viewports);
}

void CommandBuffer::Draw(DrawCall* draw)
{
	draw->Record(this);
}

void CommandBuffer::BeginRenderPass(const VkRenderPassBeginInfo& info)
{
	vkCmdBeginRenderPass(m_buffer, &info, VK_SUBPASS_CONTENTS_INLINE);
}

void CommandBuffer::BeginRenderPass(RenderPass* pass, FrameBuffer* frame, VkRect2D area)
{
	std::vector<VkClearValue> clear_values;
	const size_t count = frame->GetAttachmentCount();
	assert(count > 0);
	clear_values.reserve(count);

	for(size_t index = 0; index < count; ++index)
	{
		Image* attachment = frame->GetAttachment(index);
		VkClearValue clear_value = attachment->GetClearValue();
		clear_values.push_back(clear_value);
	}

	VkRenderPassBeginInfo render_pass_begin_info = RenderPass::BeginInfo();
	render_pass_begin_info.renderPass = pass->GetHandle();;
	render_pass_begin_info.framebuffer = frame->GetHandle();
	render_pass_begin_info.clearValueCount = clear_values.size();
	render_pass_begin_info.pClearValues = clear_values.data();
	render_pass_begin_info.renderArea = area;

	BeginRenderPass(render_pass_begin_info);
}

void CommandBuffer::EndRenderPass(void)
{
	vkCmdEndRenderPass(m_buffer);
}

void CommandBuffer::BindPipeline(Pipeline* pipeline)
{
	vkCmdBindPipeline(m_buffer, pipeline->GetBindPoint(), pipeline->GetHandle());
}

void CommandBuffer::PushConstants(PipelineLayout* layout, uint32_t offset, uint32_t size, const void* data)
{
	auto layout_handle = layout->GetHandle();
	vkCmdPushConstants(m_buffer, layout_handle, VK_SHADER_STAGE_VERTEX_BIT, offset, size, data);
}

void CommandBuffer::BindDescriptorSets(PipelineLayout* layout, const std::vector<DescriptorSet*>& sets, const std::vector<uint32_t>& offsets)
{
	std::vector<VkDescriptorSet> handles;
	handles.reserve(sets.size());
	for (auto set : sets)
	{
		handles.push_back(set->GetHandle());
	}
	assert(handles.size() > 0);
	auto layout_handle = layout->GetHandle();
	VkPipelineBindPoint point = VK_PIPELINE_BIND_POINT_GRAPHICS;

	vkCmdBindDescriptorSets(m_buffer, point, layout_handle, 0, handles.size(), handles.data(), offsets.size(), offsets.data());
}

void CommandBuffer::ClearAttachments(const VkClearAttachment* attachment, const VkClearRect* rect)
{
	assert(rect != nullptr);
	assert(attachment != nullptr);
	vkCmdClearAttachments(m_buffer, 1, attachment, 1, rect);
}

void CommandBuffer::ClearAttachments(const std::vector<VkClearAttachment>& attachments, const std::vector<VkClearRect>& rects)
{
	uint32_t num_attachment = attachments.size();
	uint32_t num_rect = rects.size();
	vkCmdClearAttachments(m_buffer, num_attachment, attachments.data(), num_rect, rects.data());
}

void CommandBuffer::CopyResource(Buffer* source, Buffer* dest, std::vector<VkBufferCopy>& regions)
{
	assert(m_begin == true);
	VkBuffer dest_buffer = dest->GetHandle();
	VkBuffer source_buffer = source->GetHandle();
	vkCmdCopyBuffer(m_buffer, source_buffer, dest_buffer, regions.size(), regions.data());
}

void CommandBuffer::CopyResource(Image* source, Buffer* dest, std::vector<VkBufferImageCopy>& regions)
{
	assert(m_begin == true);
	VkImage source_image = source->GetHandle();
	VkBuffer dest_buffer = dest->GetHandle();
	VkImageLayout layout = source->GetInfo().initialLayout;
	vkCmdCopyImageToBuffer(m_buffer, source_image, layout, dest_buffer, regions.size(), regions.data());
}

void CommandBuffer::CopyResource(Buffer* source, Image* dest, std::vector<VkBufferImageCopy>& regions)
{
	assert(m_begin == true);
	VkBuffer source_buffer = source->GetHandle();
	VkImage dest_image = dest->GetHandle();
	VkImageLayout layout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL; //dest->GetInfo().initialLayout;
	assert(source->GetUsage() & VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
	assert(dest->GetInfo().usage & VK_IMAGE_USAGE_TRANSFER_DST_BIT);
	dest->SetLayout(this, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
	vkCmdCopyBufferToImage(m_buffer, source_buffer, dest_image, layout, regions.size(), regions.data());
	dest->SetLayout(this, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
}

void CommandBuffer::CopyResource(Image* source, Image* dest, std::vector<VkImageCopy>& regions)
{
	assert(m_begin == true);
	VkImage source_image = source->GetHandle();
	VkImage dest_image = dest->GetHandle();
	VkImageLayout source_layout = source->GetInfo().initialLayout;
	VkImageLayout dest_layout = dest->GetInfo().initialLayout;
	vkCmdCopyImage(m_buffer, source_image, source_layout, dest_image, dest_layout, regions.size(), regions.data());
}

void CommandBuffer::CopyResource(Buffer* source, Buffer* dest, size_t count, const VkBufferCopy* regions)
{
	assert(m_begin == true);
	VkBuffer dest_buffer = dest->GetHandle();
	VkBuffer source_buffer = source->GetHandle();
	vkCmdCopyBuffer(m_buffer, source_buffer, dest_buffer, count, regions);
}

void CommandBuffer::CopyResource(Image* source, Buffer* dest, size_t count, const VkBufferImageCopy* regions)
{
	assert(m_begin == true);
	assert(false);
}

void CommandBuffer::CopyResource(Buffer* source, Image* dest, size_t count, const VkBufferImageCopy* regions)
{
	assert(m_begin == true);
	VkBuffer source_buffer = source->GetHandle();
	VkImage dest_image = dest->GetHandle();
	VkImageLayout layout = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
	assert(source->GetUsage() & VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
	assert(dest->GetInfo().usage & VK_IMAGE_USAGE_TRANSFER_DST_BIT);
	dest->SetLayout(this, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL);
	vkCmdCopyBufferToImage(m_buffer, source_buffer, dest_image, layout, count, regions);
	dest->SetLayout(this, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
}

void CommandBuffer::CopyResource(Image* source, Image* dest, size_t count, const VkImageCopy* regions)
{
	assert(m_begin == true);
	assert(false);
}

VkCommandBufferAllocateInfo CommandBuffer::AllocateInfo(void)
{
	VkCommandBufferAllocateInfo command_buffer_allocate_info = {};
	command_buffer_allocate_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
	command_buffer_allocate_info.pNext = NULL;
	command_buffer_allocate_info.commandPool = VK_NULL_HANDLE;
	command_buffer_allocate_info.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
	command_buffer_allocate_info.commandBufferCount = 0;
	return command_buffer_allocate_info;
}

VkCommandBufferBeginInfo CommandBuffer::BeginInfo(void)
{
	VkCommandBufferBeginInfo command_buffer_begin_info = {};
	command_buffer_begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
	command_buffer_begin_info.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
	command_buffer_begin_info.pNext = nullptr;
	command_buffer_begin_info.pInheritanceInfo = nullptr;
	return command_buffer_begin_info;
}

} /* namespace Vulkan */
