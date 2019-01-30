/*
 * VKPipeline.cpp
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#include "VKPipeline.h"
#include "VKContext.h"
#include "VKRenderPass.h"

#include "VulkanPipeline.h"
#include "VulkanInline.h"

namespace VK
{

Pipeline::Pipeline(RenderPass* pass):
		Render::Pipeline(pass)
{
}

Pipeline::~Pipeline(void)
{
	Vulkan::Release(mPipeline);
}

} /* namespace VK */
