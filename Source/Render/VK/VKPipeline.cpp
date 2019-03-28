/*
 * VKPipeline.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKPipeline.h"
#include "VKDevice.h"
#include "VKPipelineState.h"

#include "VulkanPipeline.h"
#include "VulkanInline.h"

#include <cassert>
#include <iostream>

namespace VK
{

Pipeline::Pipeline(Device* device):
		Render::Pipeline(device)
{
}

Pipeline::~Pipeline(void)
{
	Vulkan::Release(mPipeline);
}

void Pipeline::Create(Render::PipelineState* state)
{
	mPipelineState = state;
	CreateVulkanPipeline();
}

void Pipeline::CreateVulkanPipeline(void)
{
	assert(mPipeline == nullptr);
	assert(mPipelineState != nullptr);
	assert(mPipelineState->IsValid());
	auto vk_pipeline_state = static_cast<PipelineState*>(mPipelineState);
	auto pipeline_create_info = vk_pipeline_state->GetGraphicsInfo();

	auto vk_device = static_cast<Device*>(mDevice);
	auto vulkan_device = vk_device->GetVulkanDevice();
	mPipeline = Vulkan::Pipeline::New(vulkan_device);
	mPipeline->Create(nullptr, pipeline_create_info->CreateInfo());
}

} /* namespace VK */
