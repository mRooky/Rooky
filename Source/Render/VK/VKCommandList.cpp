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
#include "VKContext.h"
#include "VKResourceLayout.h"
#include "VKInline.h"

#include "VulkanCommandPool.h"
#include "VulkanCommandBuffer.h"
#include "VulkanDevice.h"
#include "VulkanPhysicalDevice.h"
#include "VulkanQueue.h"
#include "VulkanImage.h"
#include "VulkanImageView.h"
#include "VulkanSampler.h"

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

void CommandList::BeginRecord(void)
{
	assert(mCommandBuffer != nullptr);
	mCommandBuffer->Begin(VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT);
}

void CommandList::BeginPass(uint32_t index, Render::Pass* pass)
{
	mPipelineDescription.index = index;
	mPipelineDescription.pRenderPass = pass;
}

void CommandList::SetFrameBuffer(Render::FrameBuffer* frame, const Render::Rect2D& area)
{
	assert(mPipelineDescription.pRenderPass != nullptr);
	assert(mCommandBuffer != nullptr);
	RenderPass* render_pass = StaticCast(mPipelineDescription.pRenderPass);
	FrameBuffer* frame_buffer = StaticCast(frame);
	VkRect2D vulkan_area = {};
	vulkan_area.offset.x = area.offset.x;
	vulkan_area.offset.y = area.offset.y;
	vulkan_area.extent.width = area.extent.width;
	vulkan_area.extent.height = area.extent.height;
	auto vulkan_pass = render_pass->GetVulkanRenderPass();
	auto vulkan_frame = frame_buffer->GetVulkanFrameBuffer();
	mCommandBuffer->BeginRenderPass(vulkan_pass, vulkan_frame, vulkan_area);
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

void CommandList::SetScissor(uint32_t first, uint32_t count, const Render::Rect2D* rects)
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
	assert(mResourceLayout != nullptr);
	auto& traits = mPipeline->GetTraits();
	auto layout = mResourceLayout->GetCurrentLayout();
	assert(traits.pPipelineLayout == layout);
	if (traits.pPipelineLayout == layout)
	{
		auto layout = StaticCast(mResourceLayout);
		layout->Binding(this);
		assert(false);
	}
}

void CommandList::EndPass(void)
{
	assert(mCommandBuffer != nullptr);
	mCommandBuffer->EndRenderPass();
	mPipelineDescription.pRenderPass = nullptr;
}

void CommandList::EndRecord(void)
{
	assert(mCommandBuffer != nullptr);
	mCommandBuffer->End();
}

// ----------------- Main Resource Setup ------------------//
void CommandList::SetPipeline(Render::Pipeline* pipeline)
{
	assert(mCommandBuffer != nullptr);
	mPipeline = pipeline;
	Pipeline* vk_pipeline = StaticCast(pipeline);
	auto vulkan_pipeline = vk_pipeline->GetVulkanPipeline();
	mCommandBuffer->BindPipeline(vulkan_pipeline);
}

void CommandList::SetResourceLayout(Render::ResourceLayout* layout)
{
	if (mResourceLayout != layout)
	{
		mResourceLayout = layout;
		// some states trace future
	}
}

void CommandList::SetResourceState(uint32_t index, Render::ResourceState* state)
{
	assert(mResourceLayout != nullptr);
	auto layout = StaticCast(mResourceLayout);
	layout->SetResourceState(index, StaticCast(state));
}

} /* namespace VK */
