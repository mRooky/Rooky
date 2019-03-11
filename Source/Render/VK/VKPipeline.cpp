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

#include "VulkanPipeline.h"
#include "VulkanPipelineCache.h"
#include "VulkanPipelineLayout.h"
#include "VulkanInline.h"
#include "VulkanRenderPass.h"

#include <cassert>
#include <iostream>

namespace VK
{

Pipeline::Pipeline(Context* context):
		Render::Pipeline(context)
{
}

Pipeline::~Pipeline(void)
{
	mCurrent = nullptr;
	Vulkan::Release(mPipelines);
}

void Pipeline::Initialize(const Render::PipelineTraits& traits)
{
	assert(mCurrent == nullptr);
	bool valid = traits.IsValid();
	assert(valid == true);
	if (valid == true)
	{
		mTraits = traits;
		auto render_pass = StaticCast(mTraits.pRenderPass);
		auto vk_pass = render_pass->GetRenderPassVK();
		auto pipeline_state = StaticCast(mTraits.pPipelineState);
		auto pipeline_layout = StaticCast(mTraits.pPipelineLayout);
		auto vk_layout = pipeline_layout->GetPipelineLayoutVK();

		auto pipeline_create_info = pipeline_state->GetGraphicsInfo();
		pipeline_create_info->SetContent(vk_layout, vk_pass, mTraits.index);

		assert(false);

		auto device = vk_pass->GetDevice();
		mCurrent = Vulkan::Pipeline::New(device);
		mCurrent->Create(nullptr, pipeline_create_info->CreateInfo());
	}
	else
	{
		std::cout << "Pipeline Traits Is not Valid !" << std::endl;
		assert(false);
	}
	mPipelines.push_back(mCurrent);
}

void Pipeline::Update(void)
{

}

} /* namespace VK */
