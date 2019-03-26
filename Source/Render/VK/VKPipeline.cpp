/*
 * VKPipeline.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKPipeline.h"
#include "VKContext.h"
#include "VKPipelineState.h"
#include "VKPipelineLayout.h"
#include "VKRenderPass.h"
#include "VKShader.h"

#include "RenderShaderState.h"

#include "VulkanPipeline.h"
#include "VulkanPipelineCache.h"
#include "VulkanPipelineLayout.h"
#include "VulkanInline.h"
#include "VulkanRenderPass.h"
#include "VulkanShaderModule.h"

#include "UtilRelease.h"

#include <cassert>
#include <iostream>

namespace VK
{

Pipeline::Pipeline(Context* context):
		Render::Pipeline(context)
{
	Context* vk_context = static_cast<Context*>(mContext);
	mPipelineState = new PipelineState(vk_context);
}

Pipeline::~Pipeline(void)
{
	mCurrent = nullptr;
	Vulkan::Release(mPipelines);
}

void Pipeline::Create(Render::PipelineLayout* pipe_layout, Render::VertexLayout* vert_layout, Render::Pass* pass, uint32_t index)
{
	assert(mCurrent == nullptr);
	mIndex = index;
	mRenderPass = pass;
	mVertexLayout = vert_layout;
	mPipelineLayout = pipe_layout;
	CreateVulkanPipeline();
}

void Pipeline::CreateVulkanPipeline(void)
{
	auto vk_render_pass = static_cast<RenderPass*>(mRenderPass);
	auto vk_pipeline_state = static_cast<PipelineState*>(mPipelineState);
	auto vk_pipeline_layout = static_cast<PipelineLayout*>(mPipelineLayout);

	auto vulkan_pass = vk_render_pass->GetVulkanRenderPass();
	auto vulkan_pipeline_layout = vk_pipeline_layout->GetVulkanPipelineLayout();

	auto pipeline_create_info = vk_pipeline_state->GetGraphicsInfo();
	pipeline_create_info->SetContent(vulkan_pipeline_layout, vulkan_pass, mIndex);

	const size_t count = mShaderState->GetShaderCount();
	for (size_t index = 0; index < count; ++index)
	{
		auto shader = mShaderState->GetShader(index);
		auto vk_shader = static_cast<Shader*>(shader);
		auto vulkan_shader = vk_shader->GetVulkanModule();
		auto state = vk_shader->GetStage();
		auto shader_state = pipeline_create_info->CreateShaderStage();
		shader_state->stage = Shader::ConvertStage(state);
		shader_state->module = vulkan_shader->GetHandle();
	}

	auto vulkan_device = vulkan_pass->GetDevice();
	mCurrent = Vulkan::Pipeline::New(vulkan_device);
	mCurrent->Create(nullptr, pipeline_create_info->CreateInfo());
	mPipelines.push_back(mCurrent);
}

} /* namespace VK */
