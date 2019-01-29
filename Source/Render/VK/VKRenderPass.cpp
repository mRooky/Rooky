/*
 * VKRenderPass.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKRenderPass.h"
#include "VKContext.h"

#include "VulkanRenderPass.h"
#include "VulkanInline.h"

namespace VK
{

RenderPass::RenderPass(Context* context):
		Render::Pass(context)
{
}

RenderPass::~RenderPass(void)
{
	Vulkan::Release(mRenderPass);
}

} /* namespace VK */
