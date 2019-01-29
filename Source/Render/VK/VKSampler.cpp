/*
 * VKSampler.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKSampler.h"
#include "VKContext.h"

#include "VulkanSampler.h"
#include "VulkanInline.h"

namespace VK
{

Sampler::Sampler(Context* context):
		Render::Sampler(context)
{
}

Sampler::~Sampler(void)
{
	Vulkan::Release(mSampler);
}

} /* namespace VK */
