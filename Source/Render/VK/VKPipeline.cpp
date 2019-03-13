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

void Pipeline::Initialize(const Render::PipelineDescription& desc)
{
	assert(mCurrent == nullptr);
	bool valid = desc.IsValid();
	assert(valid == true);
	if (valid == true)
	{
		mDescription = desc;
		auto render_pass = StaticCast(mDescription.pRenderPass);
		auto vulkan_pass = render_pass->GetVulkanRenderPass();
		auto pipeline_state = StaticCast(mDescription.pPipelineState);
		auto pipeline_layout = StaticCast(mDescription.pPipelineLayout);
		auto vulkan_layout = pipeline_layout->GetVulkanPipelineLayout();

		auto pipeline_create_info = pipeline_state->GetGraphicsInfo();
		pipeline_create_info->SetContent(vulkan_layout, vulkan_pass, mDescription.index);

		assert(false);

		auto device = vulkan_pass->GetDevice();
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
