/*
 * VKPipelineLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "VKPipelineLayout.h"
#include "VKContext.h"
#include "VKResourceLayout.h"

#include "VulkanInline.h"
#include "VulkanPipelineLayout.h"
#include "VulkanDescriptorSetLayout.h"

#include <cassert>

namespace VK
{

PipelineLayout::PipelineLayout(ResourceLayout* layout):
		Render::PipelineLayout(layout)
{
}

PipelineLayout::~PipelineLayout(void)
{
	Vulkan::Release(mPipelineLayout);
}

void PipelineLayout::Create(const std::vector<Vulkan::DescriptorSetLayout*>& layouts)
{
	auto context = mResourceLayout->GetContext();
	Vulkan::Device* device = StaticCast(context)->GetDeviceVK();
	mPipelineLayout = Vulkan::PipelineLayout::New(device);
	mPipelineLayout->Create(layouts, mConstantRanges.size(), mConstantRanges.data());
}

} /* namespace VK */
