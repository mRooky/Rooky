/*
 * VKPipelineLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "VKPipelineLayout.h"
#include "VKContext.h"
#include "VulkanInline.h"
#include "VulkanPipelineLayout.h"
#include "VulkanDescriptorSetLayout.h"

#include <cassert>

namespace VK
{

PipelineLayout::PipelineLayout(Context* context):
		Render::PipelineLayout(context)
{
}

PipelineLayout::~PipelineLayout(void)
{
	Vulkan::Release(mPipelineLayout);
}

void PipelineLayout::Create(const std::vector<Vulkan::DescriptorSetLayout*>& layouts)
{
	Vulkan::Device* device = static_cast<Context*>(mContext)->GetDeviceVK();
	mPipelineLayout = Vulkan::PipelineLayout::New(device);
	mPipelineLayout->Create(layouts, mConstantRanges.size(), mConstantRanges.data());
}

} /* namespace VK */
