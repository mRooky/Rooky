/*
 * VKPipelineLayout.cpp
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#include "VKBindingLayout.h"
#include "VKDevice.h"
#include "VKPipelineLayout.h"
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
	auto device = mBindingLayout->GetDevice();
	Vulkan::Device* vulkan_device = static_cast<Device*>(device)->GetVulkanDevice();
	mPipelineLayout = Vulkan::PipelineLayout::New(vulkan_device);
	mPipelineLayout->Create(layouts, mConstantRanges.size(), mConstantRanges.data());
}

} /* namespace VK */
