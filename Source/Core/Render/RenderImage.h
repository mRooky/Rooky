/*
 * RenderImage.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERIMAGE_H_
#define SOURCE_CORE_RENDER_RENDERIMAGE_H_

#include "RenderColorBlend.h"
#include "RenderMemory.h"
#include "RenderLayout.hpp"

namespace Render
{
class SwapChain;
class Image : public Memory
{
protected:
	explicit Image(Device* device);

public:
	virtual ~Image(void) override;

public:
	virtual void Create(const ImageLayout& layout, const ResourceUsage& usage) = 0;

public:
	virtual void Download(void* dst) = 0;
	virtual void Upload(uint32_t index, uint32_t mipmap, const void* src) = 0;

public:
	inline Format GetFormat(void) const { return mLayout.format; }
	inline void SetClearColor(uint32_t color) { mClearColor.Set(color); }
	inline const Extent3Di& GetExtent(void) const { return mLayout.extent; }
	inline const ImageLayout& GetLayout(void) const { return mLayout; }

	inline ColorBlend* GetColorBlend(void) { return &mColorBlend; }

public:
	static bool IsDepthStencilFormat(Format format);

protected:
	Color mClearColor = {};
	ImageLayout mLayout = {};
	ColorBlend mColorBlend = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERIMAGE_H_ */
