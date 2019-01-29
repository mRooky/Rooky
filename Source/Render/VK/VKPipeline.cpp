/*
 * VKPipeline.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKPipeline.h"
#include "VKContext.h"

#include "VulkanPipeline.h"
#include "VulkanInline.h"

namespace VK
{

Pipeline::Pipeline(Context* context):
		Render::Pipeline(context)
{
}

Pipeline::~Pipeline(void)
{
	Vulkan::Release(mPipeline);
}

} /* namespace VK */
