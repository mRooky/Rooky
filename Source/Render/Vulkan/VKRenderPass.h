/*
 * VKRenderPass.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRENDERPASS_H_
#define SOURCE_RENDER_VK_VKRENDERPASS_H_

#include "GHIRenderPass.h"
#include "VKRender.h"

namespace VK
{
class Device;
class RenderPass: public GHI::RenderPass
{
public:
	explicit RenderPass(Device* device);
	virtual ~RenderPass(void) override;

public:
	virtual void Create(void) override;

public:
	virtual GHI::FrameBuffer* CreateFrameBuffer(void) override;

public:
	inline Vulkan::RenderPass* GetVulkanRenderPass(void) const { return mRenderPass; }

protected:
	Vulkan::RenderPass* mRenderPass = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRENDERPASS_H_ */
