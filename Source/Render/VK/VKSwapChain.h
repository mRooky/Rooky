/*
 * VKSwapChain.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKSWAPCHAIN_H_
#define SOURCE_RENDER_VK_VKSWAPCHAIN_H_

#include "RenderSwapChain.h"
#include "VKRender.h"

namespace VK
{
class Context;
class SwapChain: public Render::SwapChain
{
public:
	explicit SwapChain(Context* context);
	virtual ~SwapChain(void) override;

public:
	virtual void Initialize(Platform::Window* window) override;

public:
	inline Vulkan::Surface* GetSurfaceVK(void) const { return mSurface; }
	inline Vulkan::SwapChain* GetSwapChainVK(void) const { return mSwapChain; }

protected:
	Vulkan::Surface* mSurface = nullptr;
	Vulkan::SwapChain* mSwapChain = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKSWAPCHAIN_H_ */
