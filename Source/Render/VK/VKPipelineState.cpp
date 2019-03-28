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

void PipelineState::Initialize(void)
{
	assert(mRenderPass != nullptr);
	assert(mVertexLayout != nullptr);
	assert(mPipelineLayout != nullptr);

	if (false == mValid)
	{
		auto vk_render_pass = static_cast<RenderPass*>(mRenderPass);
		auto vk_pipeline_layout = static_cast<PipelineLayout*>(mPipelineLayout);

		auto vulkan_pass = vk_render_pass->GetVulkanRenderPass();
		auto vulkan_pipeline_layout = vk_pipeline_layout->GetVulkanPipelineLayout();

		mGraphicsInfo.SetContent(vulkan_pipeline_layout, vulkan_pass, mIndex);

		const size_t count = mShaderState.GetShaderCount();
		for (size_t index = 0; index < count; ++index)
		{
			auto shader = mShaderState.GetShader(index);
			auto vk_shader = static_cast<Shader*>(shader);
			auto vulkan_shader = vk_shader->GetVulkanModule();
			auto state = vk_shader->GetStage();
			auto shader_state = mGraphicsInfo.CreateShaderStage();
			shader_state->stage = Shader::ConvertStage(state);
			shader_state->module = vulkan_shader->GetHandle();
		}
	}
	mValid = true;
}

}

