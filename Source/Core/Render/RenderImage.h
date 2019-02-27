/*
 * RenderImage.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERIMAGE_H_
#define SOURCE_CORE_RENDER_RENDERIMAGE_H_

#include "RenderMemory.h"
#include "RenderFormat.h"
#include "RenderMath.h"
#include "RenderEnum.h"

namespace Render
{
class Image : public Memory
{
protected:
	explicit Image(Context* context);

public:
	virtual ~Image(void) override;

public:
	virtual void Create(ImageType type, Format format, const Extent3& extent, uint32_t usage) = 0;
	virtual void CreateView(ImageType type) = 0;

public:
	inline ImageType GetType(void) const { return mType; }
	inline ImageUsage GetUsage(void) const { return mUsage; }
	inline Format GetFormat(void) const { return mFormat; }
	inline const Extent3& GetExtent(void) const { return mExtent; }

public:
	static bool IsDepthStencilFormat(Format format);

protected:
	Extent3 mExtent = {};

protected:
	ImageUsage mUsage = {};
	Format mFormat = Format::FORMAT_UNDEFINED;
	ImageType mType = ImageType::IMAGE_TYPE_UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERIMAGE_H_ */
