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
	Vulkan::Release(mPipeline);
	if (mOwnCache == true)
	{
		Vulkan::Release(mPipelineCache);
	}
	else
	{
		mPipelineCache = nullptr;
	}
}

void Pipeline::Initialize(const Render::PipelineDetail& detail)
{
	assert(mPipeline == nullptr);
	assert(mPipelineCache != nullptr);
	bool valid = detail.IsValid();
	assert(valid == true);
	if (valid == true)
	{
		mDetail = detail;
		auto render_pass = static_cast<RenderPass*>(mDetail.pRenderPass);
		auto vk_pass = render_pass->GetRenderPassVK();

		auto pipeline_state = static_cast<PipelineState*>(mDetail.pPipelineState);

		auto pipeline_layout = static_cast<PipelineLayout*>(mDetail.pPipelineLayout);
		auto vk_layout = pipeline_layout->GetPipelineLayoutVK();

		auto pipeline_create_info = pipeline_state->GetGraphicsInfo();
		pipeline_create_info->SetContent(vk_layout, vk_pass, mDetail.index);

		assert(false);

		auto device = vk_pass->GetDevice();
		mPipeline = Vulkan::Pipeline::New(device);
		mPipeline->Create(mPipelineCache, pipeline_create_info->CreateInfo());
	}
	else
	{
		std::cout << "Pipeline Detail Is not Valid !" << std::endl;
		assert(false);
	}
}

void Pipeline::CreateCache(Vulkan::PipelineCache* cache)
{
	if (cache == nullptr)
	{
		mOwnCache = true;
		auto vk_context = static_cast<Context*>(mContext);
		Vulkan::Device* device = vk_context->GetDeviceVK();
		mPipelineCache = Vulkan::PipelineCache::New(device);
		mPipelineCache->Create(0, nullptr);
	}
}

} /* namespace VK */
