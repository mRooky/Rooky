/*
 * RenderImage.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERIMAGE_H_
#define SOURCE_CORE_RENDER_RENDERIMAGE_H_

#include "RenderMemory.h"
#include "RenderLayout.h"

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
	virtual void Create(ImageType type, Format format, const Extent3& extent, uint32_t usage) = 0;
	virtual void CreateView(ImageType type) = 0;

public:
	inline Format GetFormat(void) const { return mLayout.format; }
	inline const Extent3& GetExtent(void) const { return mLayout.extent; }

public:
	inline const ImageLayout& GetLayout(void) const { return mLayout; }

public:
	static bool IsDepthStencilFormat(Format format);

protected:
	ImageLayout mLayout = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERIMAGE_H_ */
