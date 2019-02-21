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
}

void Pipeline::Initialize(Render::Pass* pass, uint32_t index)
{
	auto render_pass = static_cast<RenderPass*>(pass);
	auto pipeline_state = static_cast<PipelineState*>(mPipelineState);

	auto vk_render_pass = render_pass->GetRenderPassVK();
	auto vk_pipeline_cache = pipeline_state->GetCache();
	auto vk_pipeline_layout = pipeline_state->GetLayout();

	auto pipeline_create_info = pipeline_state->GetGraphicsInfo();
	pipeline_create_info->SetContent(vk_pipeline_layout, vk_render_pass, index);

	auto device = vk_render_pass->GetDevice();
	mPipeline = Vulkan::Pipeline::New(device);
	mPipeline->Create(vk_pipeline_cache, pipeline_create_info->CreateInfo());

}

} /* namespace VK */
