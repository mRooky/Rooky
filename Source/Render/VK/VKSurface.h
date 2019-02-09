/*
 * VKSwapChain.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKSWAPCHAIN_H_
#define SOURCE_RENDER_VK_VKSWAPCHAIN_H_

#include "RenderSurface.h"
#include "VKRender.h"

namespace VK
{
class Context;
class Surface: public Render::Surface
{
public:
	explicit Surface(Context* context);
	virtual ~Surface(void) override;

public:
	virtual void Create(Platform::Window* window) override;

public:
	inline Vulkan::Surface* GetSurfaceVK(void) const { return mSurface; }
	inline Vulkan::SwapChain* GetSwapChainVK(void) const { return mSwapChain; }

protected:
	Vulkan::Surface* mSurface = nullptr;
	Vulkan::SwapChain* mSwapChain = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKSWAPCHAIN_H_ */
