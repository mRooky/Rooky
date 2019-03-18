/*
 * RenderImage.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERIMAGE_H_
#define SOURCE_CORE_RENDER_RENDERIMAGE_H_

#include "RenderMemory.h"
#include "RenderLayout.hpp"

namespace Render
{
class Image : public Memory
{
protected:
	explicit Image(Context* context);

public:
	virtual ~Image(void) override;

public:
	virtual void Create(const ImageLayout& layout) = 0;

public:
	virtual void Download(void* dst) = 0;
	virtual void Upload(uint32_t index, uint32_t mipmap, const void* src) = 0;

public:
	inline Format GetFormat(void) const { return mLayout.format; }
	inline void SetClearColor(uint32_t color) { mClearColor.Set(color); }
	inline const Extent3D& GetExtent(void) const { return mLayout.extent; }

public:
	inline const ImageLayout& GetLayout(void) const { return mLayout; }

public:
	static bool IsDepthStencilFormat(Format format);

protected:
	Color mClearColor = {};
	ImageLayout mLayout = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERIMAGE_H_ */
