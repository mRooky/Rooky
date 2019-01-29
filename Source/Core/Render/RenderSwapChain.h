/*
 * RenderSwapChain.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSWAPCHAIN_H_
#define SOURCE_CORE_RENDER_RENDERSWAPCHAIN_H_

#include "RenderObject.h"
#include "PlatformWindow.h"

namespace Render
{
class Image;
class SwapChain: public Object
{
protected:
	explicit SwapChain(Context* context);
	virtual ~SwapChain(void) override;

public:
	virtual void Initialize(Platform::Window* window) = 0;

public:
	inline Image* GetDepthStencil(void) const { return mDepthStencil; }

protected:
	Image* mDepthStencil = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSWAPCHAIN_H_ */
