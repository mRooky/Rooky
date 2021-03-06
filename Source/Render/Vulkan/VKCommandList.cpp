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
#include "VKPipelineLayout.h"
#include "VKBindingSet.h"

#include "../../Core/GHI/GHIBindingLayout.h"
#include "../../Core/GHI/GHIPipelineState.h"
#include "../../Core/GHI/GHIFrameLayout.h"
#include "../../Core/GHI/Draw/GHIDrawIndexed.h"

#include "../../Platform/Vulkan/VulkanCommandPool.h"
#include "../../Platform/Vulkan/VulkanCommandBuffer.h"
#include "../../Platform/Vulkan/VulkanDevice.h"
#include "../../Platform/Vulkan/VulkanPhysicalDevice.h"
#include "../../Platform/Vulkan/VulkanQueue.h"
#include "../../Platform/Vulkan/VulkanImage.h"
#include "../../Platform/Vulkan/VulkanImageView.h"
#include "../../Platform/Vulkan/VulkanSampler.h"
#include "../../Platform/Vulkan/VulkanRenderPass.h"
#include "../../Platform/Vulkan/VulkanFrameBuffer.h"
#include "../../Platform/Vulkan/VulkanDrawCall.h"

#include <cassert>

namespace VK
{

CommandList::CommandList(CommandPool* pool):
		GHI::CommandList(pool)
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

void CommandList::Begin(void)
{
	assert(mBegin == false);
	assert(mCommandBuffer != nullptr);
	mBegin = true;
	mCommandBuffer->Begin(VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT);
}

void CommandList::BeginPass(GHI::RenderPass* pass, GHI::FrameBuffer* frame, const Math::Rect2Di& area)
{
	assert(pass != nullptr);
	assert(mCommandBuffer != nullptr);
	RenderPass* vk_pass = static_cast<RenderPass*>(pass);
	FrameBuffer* vk_frame = static_cast<FrameBuffer*>(frame);
	auto vulkan_pass = vk_pass->GetVulkanRenderPass();
	auto vulkan_frame = vk_frame->GetVulkanFrameBuffer();

	std::vector<VkClearValue> clear_values;
	const auto& layout = frame->GetLayout();
	const size_t count = layout.GetImageCount();
	assert(count > 0);
	clear_values.reserve(count);

	for(size_t index = 0; index < count; ++index)
	{
		auto vk_image = static_cast<Image*>(layout.GetImage(index));
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

void CommandList::SetViewport(uint32_t first, uint32_t count, const Math::Viewport* viewports)
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

void CommandList::SetScissor(uint32_t first, uint32_t count, const Math::Rect2Di* rects)
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

// ----------------- Main Resource Setup ------------------//
void CommandList::SetPipeline(GHI::Pipeline* pipeline)
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

void CommandList::SetBindingSet(uint32_t slot, GHI::BindingSet* set)
{
	assert(mBindingLayout != nullptr);
	mBindingLayout->PushBindingSet(slot, set);
	assert(false);
}

void CommandList::SetVertex(const GHI::Resource* buffer, uint32_t binding, size_t offset)
{
	assert(buffer != nullptr);
	assert(mCommandBuffer != nullptr);
	const Buffer* vk_buffer = static_cast<const Buffer*>(buffer);
	Vulkan::Buffer* vulkan_buffer = vk_buffer->GetVulkanBuffer();
	mCommandBuffer->BindVertexBuffers(vulkan_buffer, binding, offset);
}

void CommandList::SetIndex(const GHI::Resource* buffer, size_t offset, GHI::IndexType type)
{
	assert(buffer != nullptr);
	assert(mCommandBuffer != nullptr);
	const Buffer* vk_buffer = static_cast<const Buffer*>(buffer);
	Vulkan::Buffer* vulkan_buffer = vk_buffer->GetVulkanBuffer();
	VkIndexType index_type = Convert(type);
	mCommandBuffer->BindIndexBuffer(vulkan_buffer, offset, index_type);
}

void CommandList::Draw(GHI::Draw* draw)
{
	BindingResource();
	auto type = draw->GetType();
	switch(type)
	{
	case GHI::DrawType::DRAW_TYPE_ARRAY:
		assert(false);
		break;
	case GHI::DrawType::DRAW_TYPE_INDEXED:
		DrawIndexed(draw);
		break;
	case GHI::DrawType::DRAW_TYPE_INDEXED_INDIRECT:
		assert(false);
		break;
	case GHI::DrawType::DRAW_TYPE_INDIRECT:
		assert(false);
		break;
	default:
		assert(false);
	}
}

void CommandList::EndPass(void)
{
	assert(mCommandBuffer != nullptr);
	mCommandBuffer->EndRenderPass();
}

void CommandList::End(void)
{
	assert(mBegin == true);
	assert(mCommandBuffer != nullptr);
	mBegin = false;
	mCommandBuffer->End();
}

void CommandList::BindingResource(void)
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

void CommandList::DrawIndexed(GHI::Draw* draw)
{
	GHI::DrawIndexed* index = static_cast<GHI::DrawIndexed*>(draw);
	Vulkan::DrawIndexed vulkan_index = {};
	vulkan_index.SetIndexCount(index->GetIndexCount());
	mCommandBuffer->Draw(&vulkan_index);
}

} /* namespace VK */
