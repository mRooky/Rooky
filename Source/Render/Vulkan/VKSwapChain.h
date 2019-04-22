/*
 * VKSwapChain.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKSWAPCHAIN_H_
#define SOURCE_RENDER_VK_VKSWAPCHAIN_H_

#include "GHISwapChain.h"
#include "VKRender.h"

namespace VK
{
class Device;
class SwapChain: public GHI::SwapChain
{
public:
	explicit SwapChain(Device* device);
	virtual ~SwapChain(void) override;

public:
	virtual void Create(Platform::Window* window) override;

public:
	virtual void SwapBuffer(uint32_t index) override;
	virtual uint32_t AcquireNextImage(void) override;

public:
	inline Vulkan::Surface* GetVulkanSurface(void) const { return mSurface; }
	inline Vulkan::SwapChain* GetVulkanSwapChain(void) const { return mSwapChain; }

private:
	void GetSwapChainRenderBuffer(void);

protected:
	Vulkan::Surface* mSurface = nullptr;
	Vulkan::SwapChain* mSwapChain = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKSWAPCHAIN_H_ */
