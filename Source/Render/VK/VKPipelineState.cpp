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

#include "VulkanShaderModule.h"

#include <cassert>

namespace VK
{

PipelineState::PipelineState(Device* device):
		Render::PipelineState(device)
{
}

PipelineState::~PipelineState(void)
{
}

void PipelineState::Create(void)
{
	if (false == mValid)
	{
		CreateVulkanLayoutInfo();
		CreateVulkanViewportInfo();
		CreateVulkanRenderPassInfo();
		CreateVulkanShaderStageInfo();
		CreateVulkanVertexInputInfo();
		CreateVulkanColorBlendInfo();
		mValid = true;
	}
}

void PipelineState::CreateVulkanRenderPassInfo(void)
{
	assert(mRenderPass != nullptr);

	auto vk_render_pass = static_cast<RenderPass*>(mRenderPass);
	auto vulkan_pass = vk_render_pass->GetVulkanRenderPass();

	mGraphicsInfo.SetContent(vulkan_pass, mIndex);
}

void PipelineState::CreateVulkanViewportInfo(void)
{
	//Empty
}

void PipelineState::CreateVulkanColorBlendInfo(void)
{
	//mPipelineCommon;
	auto state = mGraphicsInfo.GetColorBlendStateInfo()->CreateAttachmentState(false);
	assert(state != nullptr);
}

void PipelineState::CreateVulkanLayoutInfo(void)
{
	assert(mPipelineLayout != nullptr);
	auto vk_pipeline_layout = static_cast<PipelineLayout*>(mPipelineLayout);
	auto vulkan_pipeline_layout = vk_pipeline_layout->GetVulkanPipelineLayout();
	mGraphicsInfo.SetContent(vulkan_pipeline_layout);
}

void PipelineState::CreateVulkanShaderStageInfo(void)
{
	assert(mShaderState != nullptr);
	const size_t count = mShaderState->GetShaderCount();
	for (size_t index = 0; index < count; ++index)
	{
		auto shader = mShaderState->GetShader(index);
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
	auto vk_vertex_layout = static_cast<VertexLayout*>(mVertexLayout);
	auto input_state_info = vk_vertex_layout->GetVertexInputStateInfo();
	(*mGraphicsInfo.GetVertexInputStateInfo()) = (*input_state_info);
}

}

