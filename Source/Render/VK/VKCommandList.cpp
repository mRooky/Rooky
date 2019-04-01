/*
 * CommandList.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKCommandList.h"
#include "VKCommandPool.h"
#include "VKRenderPass.h"
#include "VKFrameBuffer.h"
#include "VKPipeline.h"
#include "VKImage.h"
#include "VKSampler.h"
#include "VKShader.h"
#include "VKInline.h"
#include "VKQueue.h"
#include "VKDevice.h"
#include "VKBuffer.h"
#include "VKConvert.h"
#include "VKPipelineState.h"
#include "VKPipelineLayout.h"
#include "VKBindingSet.h"

#include "VulkanCommandPool.h"
#include "VulkanCommandBuffer.h"
#include "VulkanDevice.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanQueue.h"
#include "VulkanImage.h"
#include "VulkanImageView.h"
#include "VulkanSampler.h"
#include "VulkanRenderPass.h"
#include "VulkanFrameBuffer.h"

#include "RenderBindingLayout.h"

#include <cassert>

namespace VK
{

CommandList::CommandList(CommandPool* pool):
		Render::CommandList(pool)
{
}

CommandList::~CommandList(void)
{
	mCommandBuffer = nullptr;
}

void CommandList::Create(bool primary)
{
	assert(mCommandPool != nullptr);
	VkCommandBufferLevel level =  primary ? VK_COMMAND_BUFFER_LEVEL_PRIMARY : VK_COMMAND_BUFFER_LEVEL_SECONDARY;
	auto command_pool = static_cast<CommandPool*>(mCommandPool);
	auto vulkan_command_pool = command_pool->GetVulkanCommandPool();
	mCommandBuffer = vulkan_command_pool->Allocate(level);
}

void CommandList::Submit(uint32_t index)
{
	assert(mCommandBuffer != nullptr);
	auto device = mCommandBuffer->GetDevice();
	auto physical = device->GetPhysicalDevice();
	uint32_t family = physical->GetFamily();
	auto queue = device->GetQueue(family, index);
	{
		auto command_buffer = mCommandBuffer->GetHandle();
		VkPipelineStageFlags wait_stage_mask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
		VkSubmitInfo submit_info = {};
		submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
		submit_info.pWaitDstStageMask = &wait_stage_mask;
		submit_info.commandBufferCount = 1;
		submit_info.pCommandBuffers = &command_buffer;
		queue->Submit(1, &submit_info);
	}
}

void CommandList::Submit(Render::Queue* queue)
{
	assert(mCommandBuffer != nullptr);
	assert(queue != nullptr);
	auto command_buffer = mCommandBuffer->GetHandle();
	VkPipelineStageFlags wait_stage_mask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
	VkSubmitInfo submit_info = {};
	submit_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
	submit_info.pWaitDstStageMask = &wait_stage_mask;
	submit_info.commandBufferCount = 1;
	submit_info.pCommandBuffers = &command_buffer;

	auto vk_queue = static_cast<Queue*>(queue);
	auto vulkan_queue = vk_queue->GetVulkanQueue();
	vulkan_queue->Submit(1, &submit_info);
}

void CommandList::Begin(void)
{
	assert(mCommandBuffer != nullptr);
	mCommandBuffer->Begin(VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT);
}

void CommandList::BeginPass(Render::Pass* pass, Render::FrameBuffer* frame, const Render::Rect2Di& area)
{
	assert(pass != nullptr);
	assert(mCommandBuffer != nullptr);
	RenderPass* vk_pass = static_cast<RenderPass*>(pass);
	FrameBuffer* vk_frame = static_cast<FrameBuffer*>(frame);
	auto vulkan_pass = vk_pass->GetVulkanRenderPass();
	auto vulkan_frame = vk_frame->GetVulkanFrameBuffer();

	std::vector<VkClearValue> clear_values;
	const size_t count = frame->GetAttachmentCount();
	assert(count > 0);
	clear_values.reserve(count);

	for(size_t index = 0; index < count; ++index)
	{
		auto vk_image = static_cast<Image*>(frame->GetAttachment(index));
		VkClearValue clear_value = vk_image->GetClearValue();
		clear_values.push_back(clear_value);
	}

	auto render_pass_begin_info = Vulkan::RenderPass::BeginInfo();
	render_pass_begin_info.renderPass = vulkan_pass->GetHandle();
	render_pass_begin_info.framebuffer = vulkan_frame->GetHandle();
	render_pass_begin_info.clearValueCount = clear_values.size();
	render_pass_begin_info.pClearValues = clear_values.data();
	render_pass_begin_info.renderArea.offset.x = area.offset.x;
	render_pass_begin_info.renderArea.offset.y = area.offset.y;
	render_pass_begin_info.renderArea.extent.width = area.extent.width;
	render_pass_begin_info.renderArea.extent.height = area.extent.height;

	mCommandBuffer->BeginRenderPass(render_pass_begin_info);
}

void CommandList::SetViewport(uint32_t first, uint32_t count, const Render::Viewport* viewports)
{
	assert(mCommandBuffer != nullptr);
	std::vector<VkViewport> vulkan_viewports;
	vulkan_viewports.reserve(count);
	for (uint32_t i = 0; i < count; ++i)
	{
		auto current = viewports + i;
		VkViewport vulkan_viewport = {};
		vulkan_viewport.x = current->x;
		vulkan_viewport.y = current->y;
		vulkan_viewport.width = current->width;
		vulkan_viewport.height = current->height;
		vulkan_viewport.minDepth = current->minDepth;
		vulkan_viewport.maxDepth = current->maxDepth;
		vulkan_viewports.push_back(vulkan_viewport);
	}
	mCommandBuffer->SetViewport(first, count, vulkan_viewports.data());
}

void CommandList::SetScissor(uint32_t first, uint32_t count, const Render::Rect2Di* rects)
{
	assert(mCommandBuffer != nullptr);
	std::vector<VkRect2D> vulkan_scissors;
	vulkan_scissors.reserve(count);
	for (uint32_t i = 0; i < count; ++i)
	{
		auto current = rects + i;
		VkRect2D vulkan_scissor = {};
		vulkan_scissor.offset.x = current->offset.x;
		vulkan_scissor.offset.y = current->offset.y;
		vulkan_scissor.extent.width = current->extent.width;
		vulkan_scissor.extent.height = current->extent.height;
		vulkan_scissors.push_back(vulkan_scissor);
	}
	mCommandBuffer->SetScissor(first, count, vulkan_scissors.data());
}

void CommandList::Draw(Render::DrawCall* draw)
{
	assert(mPipeline != nullptr);
	assert(mBindingLayout != nullptr);
	const size_t count = mBindingLayout->GetSetCount();
	assert(count > 0);
	std::vector<Vulkan::DescriptorSet*> descriptor_sets;
	descriptor_sets.reserve(count);

	for(size_t index = 0; index < count; ++index)
	{
		auto set = mBindingLayout->GetBindingSet(index);
		assert(set->IsValid());
		auto vk_set = static_cast<const BindingSet*>(set);
		Vulkan::DescriptorSet* vulkan_set = vk_set->GetDescriptorSet();
		descriptor_sets.push_back(vulkan_set);
	}

	std::vector<uint32_t> offset;

	auto pipeline_layout = mPipeline->GetState()->GetLayout();
	auto vk_pipeline_layout = static_cast<PipelineLayout*>(pipeline_layout);
	auto vulkan_pipeline_layout = vk_pipeline_layout->GetVulkanPipelineLayout();
	mCommandBuffer->BindDescriptorSets(vulkan_pipeline_layout, descriptor_sets, offset);
}

void CommandList::EndPass(void)
{
	assert(mCommandBuffer != nullptr);
	mCommandBuffer->EndRenderPass();
}

void CommandList::End(void)
{
	assert(mCommandBuffer != nullptr);
	mCommandBuffer->End();
}

// ----------------- Main Resource Setup ------------------//
void CommandList::SetPipeline(Render::Pipeline* pipeline)
{
	assert(mCommandBuffer != nullptr);
	mPipeline = pipeline;
	Pipeline* vk_pipeline = static_cast<Pipeline*>(pipeline);
	auto vulkan_pipeline = vk_pipeline->GetVulkanPipeline();
	mCommandBuffer->BindPipeline(vulkan_pipeline);
	auto pipeline_state = mPipeline->GetState();
	auto pipeline_layout = pipeline_state->GetLayout();
	mBindingLayout = pipeline_layout->GetBindingLayout();
}

void CommandList::SetBindingSet(uint32_t slot, Render::BindingSet* set)
{
	assert(mBindingLayout != nullptr);
	mBindingLayout->SetBindingSet(slot, set);
	assert(false);
}

void CommandList::SetVertex(Render::Buffer* buffer, uint32_t binding, size_t offset)
{
	assert(buffer != nullptr);
	assert(mCommandBuffer != nullptr);
	Buffer* vk_buffer = static_cast<Buffer*>(buffer);
	Vulkan::Buffer* vulkan_buffer = vk_buffer->GetVulkanBuffer();
	mCommandBuffer->BindVertexBuffers(vulkan_buffer, binding, offset);
}

void CommandList::SetIndex(Render::Buffer* buffer, size_t offset, Render::IndexType type)
{
	assert(buffer != nullptr);
	assert(mCommandBuffer != nullptr);
	Buffer* vk_buffer = static_cast<Buffer*>(buffer);
	Vulkan::Buffer* vulkan_buffer = vk_buffer->GetVulkanBuffer();
	VkIndexType index_type = Convert(type);
	mCommandBuffer->BindIndexBuffer(vulkan_buffer, offset, index_type);
}

} /* namespace VK */
