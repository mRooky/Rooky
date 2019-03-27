/*
 * VKSampler.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKSampler.h"
#include "VulkanSampler.h"
#include "VulkanInline.h"
#include "VKDevice.h"

namespace VK
{

Sampler::Sampler(Device* device):
		Render::Sampler(device)
{
}

Sampler::~Sampler(void)
{
	Vulkan::Release(mSampler);
}

} /* namespace VK */
