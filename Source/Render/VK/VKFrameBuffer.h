/*
 * VKFrameBuffer.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKFRAMEBUFFER_H_
#define SOURCE_RENDER_VK_VKFRAMEBUFFER_H_

#include "RenderFrameBuffer.h"
#include "VKRender.h"

namespace VK
{
class RenderPass;
class FrameBuffer: public Render::FrameBuffer
{
public:
	explicit FrameBuffer(RenderPass* pass);
	virtual ~FrameBuffer(void) override;

public:
	virtual void Create(const Render::Extent2D& extent) override;

public:
	inline Vulkan::FrameBuffer* GetVulkanFrameBuffer(void) const { return mFrameBuffer; }

protected:
	Vulkan::FrameBuffer* mFrameBuffer = nullptr;
};

static inline FrameBuffer* StaticCast(Render::FrameBuffer* frame)
{
	return static_cast<FrameBuffer*>(frame);
}

static inline FrameBuffer* SaftyCast(Render::FrameBuffer* frame)
{
	return dynamic_cast<FrameBuffer*>(frame);
}

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKFRAMEBUFFER_H_ */
