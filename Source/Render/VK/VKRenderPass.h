/*
 * VKRenderPass.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRENDERPASS_H_
#define SOURCE_RENDER_VK_VKRENDERPASS_H_

#include "RenderPass.h"
#include "VKRender.h"

namespace VK
{
class Context;
class RenderPass: public Render::Pass
{
public:
	explicit RenderPass(Context* context);
	virtual ~RenderPass(void) override;

public:
	virtual void Create(void) override;

public:
	virtual Render::FrameBuffer* CreateFrameBuffer(void) override;

public:
	inline Vulkan::RenderPass* GetVulkanRenderPass(void) const { return mRenderPass; }

protected:
	Vulkan::RenderPass* mRenderPass = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRENDERPASS_H_ */
