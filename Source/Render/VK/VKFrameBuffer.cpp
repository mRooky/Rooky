/*
 * VKFrameBuffer.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKFrameBuffer.h"
#include "VKContext.h"

#include "VulkanFrameBuffer.h"
#include "VulkanInline.h"

namespace VK
{

FrameBuffer::FrameBuffer(Context* context):
		Render::FrameBuffer(context)
{
}

FrameBuffer::~FrameBuffer(void)
{
	Vulkan::Release(mFrameBuffer);
}

} /* namespace VK */
