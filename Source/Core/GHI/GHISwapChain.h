/*
 * RenderSwapChain.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERSWAPCHAIN_H_
#define SOURCE_CORE_GHI_RENDERSWAPCHAIN_H_

#include "GHIFormat.h"
#include "GHIObject.h"
#include "GHIColorBlend.h"
#include "PlatformWindow.h"
#include "MathExtent.h"

#include <cstdint>
#include <vector>

namespace GHI
{
class Image;
class SwapChain: public Object
{
protected:
	explicit SwapChain(Device* device);

public:
	virtual ~SwapChain(void) override;

public:
	virtual void Create(Platform::Window* window) = 0;

public:
	virtual void SwapBuffer(uint32_t index) = 0;
	virtual uint32_t AcquireNextImage(void) = 0;

public:
	inline Format GetFormat(void) const { return mFormat; }
	inline ColorBlend* GetColorBlend(void) { return &mColorBlend; }
	inline const Math::Extent2Di& GetExtent(void) const { return mExtent; }
	inline size_t GetRenderBufferCount(void) const { return mRenderBuffers.size(); }
	inline Image* GetRenderBuffer(size_t index) const { return mRenderBuffers.at(index); }

protected:
	ColorBlend mColorBlend = {};
	Math::Extent2Di mExtent = {};
	std::vector<Image*> mRenderBuffers;
	Format mFormat = Format::FORMAT_UNDEFINED;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERSWAPCHAIN_H_ */
