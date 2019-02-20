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

#include <cstdint>
#include <vector>

namespace Render
{
class Image;
class SwapChain: public Object
{
protected:
	explicit SwapChain(Context* context);

public:
	virtual ~SwapChain(void) override;

public:
	virtual void Create(Platform::Window* window) = 0;

public:
	virtual void SwapBuffer(uint32_t index) = 0;
	virtual uint32_t AcquireNextImage(void) = 0;

public:
	inline size_t GetRenderBufferCount(void) const { return mRenderBuffers.size(); }
	inline Image* GetRenderBuffer(size_t index) const { return mRenderBuffers.at(index); }

protected:
	std::vector<Image*> mRenderBuffers;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSWAPCHAIN_H_ */