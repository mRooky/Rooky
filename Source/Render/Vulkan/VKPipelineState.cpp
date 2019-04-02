/*
 * VKPipelineState.cpp
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */


#include "VKPipelineState.h"
#include "VKPipeline.h"
#include "VKDevice.h"
#include "VKPipelineLayout.h"
#include "VKRenderPass.h"
#include "VKShader.h"
#include "VKVertexLayout.h"

#include "RenderPipelineState.h"

#include "VulkanShaderModule.h"

#include <cassert>

namespace VK
{

PipelineState::PipelineState(void)
{
}

PipelineState::~PipelineState(void)
{
}

void PipelineState::Create(const Render::PipelineState* state)
{
	if (false == mValid)
	{
		mState = state;
		assert(state != nullptr);
		CreateVulkanLayoutInfo();
		CreateVulkanViewportInfo();
		CreateVulkanRenderPassInfo();
		CreateVulkanShaderStageInfo();
		CreateVulkanVertexInputInfo();
		CreateVulkanColorBlendInfo(true);
		CreateVulkanDepthStencil();
		mValid = true;
	}
}

void PipelineState::CreateVulkanRenderPassInfo(void)
{
	auto render_pass = mState->GetRenderPass();
	assert(render_pass != nullptr);

	auto vk_render_pass = static_cast<RenderPass*>(render_pass);
	auto vulkan_pass = vk_render_pass->GetVulkanRenderPass();

	uint32_t index = mState->GetSubIndex();
	mGraphicsInfo.SetContent(vulkan_pass, index);
}

void PipelineState::CreateVulkanViewportInfo(void)
{
	//Empty
}

void PipelineState::CreateVulkanColorBlendInfo(bool blend)
{
	//mPipelineCommon;
	auto state = mGraphicsInfo.GetColorBlendStateInfo()->CreateAttachmentState(blend);
	assert(state != nullptr);
}

void PipelineState::CreateVulkanLayoutInfo(void)
{
	auto pipeline_layout = mState->GetLayout();
	assert(pipeline_layout != nullptr);
	auto vk_pipeline_layout = static_cast<PipelineLayout*>(pipeline_layout);
	auto vulkan_pipeline_layout = vk_pipeline_layout->GetVulkanPipelineLayout();
	mGraphicsInfo.SetContent(vulkan_pipeline_layout);
}

void PipelineState::CreateVulkanShaderStageInfo(void)
{
	auto& shader_state = mState->GetShaderState();
	const size_t count = shader_state.GetShaderCount();
	for (size_t index = 0; index < count; ++index)
	{
		auto shader = shader_state.GetShader(index);
		auto vk_shader = static_cast<Shader*>(shader);
		auto vulkan_shader = vk_shader->GetVulkanModule();
		auto state = vk_shader->GetStage();
		auto shader_state = mGraphicsInfo.CreateShaderStage();
		shader_state->stage = Shader::ConvertStage(state);
		shader_state->module = vulkan_shader->GetHandle();
	}
}

void PipelineState::CreateVulkanVertexInputInfo(void)
{
	auto vertex_layout = mState->GetVertexLayout();
	assert(vertex_layout != nullptr);
	auto vk_vertex_layout = static_cast<VertexLayout*>(vertex_layout);
	auto input_state_info = vk_vertex_layout->GetVertexInputStateInfo();
	(*mGraphicsInfo.GetVertexInputStateInfo()) = (*input_state_info);
}

void PipelineState::CreateVulkanDepthStencil(void)
{

}

}

