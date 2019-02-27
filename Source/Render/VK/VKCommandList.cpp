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
#include "VKResourceSet.h"
#include "VKImage.h"
#include "VKSampler.h"

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
	auto vk_command_pool = command_pool->GetCommandPoolVK();
	mCommandBuffer = vk_command_pool->Allocate(level);
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
	assert(mCurrentPass == nullptr);
	mIndex = index;
	mCurrentPass = pass;
}

void CommandList::BindFrameBuffer(Render::FrameBuffer* frame, const Render::Rect2D& area)
{
	assert(mCurrentPass != nullptr);
	assert(mCommandBuffer != nullptr);
	RenderPass* render_pass = static_cast<RenderPass*>(mCurrentPass);
	FrameBuffer* frame_buffer = static_cast<FrameBuffer*>(frame);
	VkRect2D vk_area = {};
	vk_area.offset.x = area.offset.x;
	vk_area.offset.y = area.offset.y;
	vk_area.extent.width = area.extent.width;
	vk_area.extent.height = area.extent.height;
	mCommandBuffer->BeginRenderPass(render_pass->GetRenderPassVK(), frame_buffer->GetFrameBufferVK(), vk_area);
}

void CommandList::BindPipeline(Render::Pipeline* pipeline)
{
	assert(mCommandBuffer != nullptr);
	Pipeline* vk_pipeline = static_cast<Pipeline*>(pipeline);
	mCommandBuffer->BindPipeline(vk_pipeline->GetPipelineVK());
}

void CommandList::SetViewport(uint32_t first, uint32_t count, const Render::Viewport* viewports)
{
	assert(mCommandBuffer != nullptr);
	std::vector<VkViewport> vk_viewports;
	vk_viewports.reserve(count);
	for (uint32_t i = 0; i < count; ++i)
	{
		auto current = viewports + i;
		VkViewport vk_viewport = {};
		vk_viewport.x = current->x;
		vk_viewport.y = current->y;
		vk_viewport.width = current->width;
		vk_viewport.height = current->height;
		vk_viewport.minDepth = current->minDepth;
		vk_viewport.maxDepth = current->maxDepth;
		vk_viewports.push_back(vk_viewport);
	}
	mCommandBuffer->SetViewport(first, count, vk_viewports.data());
}

void CommandList::SetScissor(uint32_t first, uint32_t count, const Render::Rect2D* rects)
{
	assert(mCommandBuffer != nullptr);
	std::vector<VkRect2D> vk_scissors;
	vk_scissors.reserve(count);
	for (uint32_t i = 0; i < count; ++i)
	{
		auto current = rects + i;
		VkRect2D vk_scissor = {};
		vk_scissor.offset.x = current->offset.x;
		vk_scissor.offset.y = current->offset.y;
		vk_scissor.extent.width = current->extent.width;
		vk_scissor.extent.height = current->extent.height;
		vk_scissors.push_back(vk_scissor);
	}
	mCommandBuffer->SetScissor(first, count, vk_scissors.data());
}

void CommandList::Draw(Render::DrawCall* draw)
{
	assert(false);
}

void CommandList::EndPass(void)
{
	assert(mCommandBuffer != nullptr);
	mCommandBuffer->EndRenderPass();
	mCurrentPass = nullptr;
}

void CommandList::EndRecord(void)
{
	assert(mCommandBuffer != nullptr);
	mCommandBuffer->End();
}

void CommandList::SetBuffer(Render::ShaderStage stage, uint32_t index, Render::Buffer* image)
{

}

void CommandList::SetImage(Render::ShaderStage stage, uint32_t index, Render::Image* image, Render::Sampler* sampler)
{
	Image* vk_image = static_cast<Image*>(image);
	VkDescriptorImageInfo* image_info = nullptr;
	assert(false);
	image_info->imageView = vk_image->GetImageVK()->GetView()->GetHandle();
	image_info->imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
	if (sampler != nullptr)
	{
		Sampler* vk_sampler = static_cast<Sampler*>(sampler);
		image_info->sampler = vk_sampler->GetSamplerVK()->GetHandle();
	}
}

} /* namespace VK */
