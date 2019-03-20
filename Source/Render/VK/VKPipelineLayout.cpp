/*
 * VKPipelineLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include <VKBindingLayout.h>
#include "VKPipelineLayout.h"
#include "VKContext.h"
#include "VulkanInline.h"
#include "VulkanPipelineLayout.h"
#include "VulkanDescriptorSetLayout.h"

#include <cassert>

namespace VK
{

PipelineLayout::PipelineLayout(BindingLayout* layout):
		Render::PipelineLayout(layout)
{
}

PipelineLayout::~PipelineLayout(void)
{
	Vulkan::Release(mPipelineLayout);
}

void PipelineLayout::Create(const std::vector<Vulkan::DescriptorSetLayout*>& layouts)
{
	auto context = mBindingLayout->GetContext();
	Vulkan::Device* device = StaticCast(context)->GetVulkanDevice();
	mPipelineLayout = Vulkan::PipelineLayout::New(device);
	mPipelineLayout->Create(layouts, mConstantRanges.size(), mConstantRanges.data());
}

} /* namespace VK */
