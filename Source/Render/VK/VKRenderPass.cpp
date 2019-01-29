/*
 * VKRenderPass.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKRenderPass.h"
#include "VKFrameBuffer.h"
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

Render::FrameBuffer* RenderPass::CreateFrameBuffer(void)
{
	FrameBuffer* frame_buffer = new FrameBuffer(this);
	mFrameBuffers.push_back(frame_buffer);
	return frame_buffer;
}

} /* namespace VK */
