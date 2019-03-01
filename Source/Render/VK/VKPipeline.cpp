/*
 * VKPipeline.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKPipeline.h"
#include "VKContext.h"
#include "VKPipelineState.h"
#include "VKRenderPass.h"

#include "VulkanPipeline.h"
#include "VulkanPipelineCache.h"
#include "VulkanInline.h"
#include "VulkanRenderPass.h"

#include <cassert>

namespace VK
{

Pipeline::Pipeline(PipelineState* state):
		Render::Pipeline(state)
{
}

Pipeline::~Pipeline(void)
{
	Vulkan::Release(mPipeline);
	Vulkan::Release(mPipelineCache);
	mPipelineLayout = nullptr;
}

void Pipeline::Initialize(Render::Pass* pass, uint32_t index)
{
	assert(mPipeline == nullptr);
	assert(mPipelineCache != nullptr);
	assert(mPipelineLayout != nullptr);

	mRenderPass = pass;

	auto render_pass = static_cast<RenderPass*>(pass);
	auto pipeline_state = static_cast<PipelineState*>(mPipelineState);
	auto vk_render_pass = render_pass->GetRenderPassVK();

	auto pipeline_create_info = pipeline_state->GetGraphicsInfo();
	pipeline_create_info->SetContent(mPipelineLayout, vk_render_pass, index);

	auto device = vk_render_pass->GetDevice();
	mPipeline = Vulkan::Pipeline::New(device);
	mPipeline->Create(mPipelineCache, pipeline_create_info->CreateInfo());

}

void Pipeline::CreateCache(Vulkan::PipelineCache* cache)
{
	if (cache == nullptr)
	{
		assert(mRenderPass != nullptr);
		auto context = mRenderPass->GetContext();
		auto vk_context = static_cast<Context*>(context);
		Vulkan::Device* device = vk_context->GetDeviceVK();
		mPipelineCache = Vulkan::PipelineCache::New(device);
		mPipelineCache->Create(0, nullptr);
	}
}

} /* namespace VK */
