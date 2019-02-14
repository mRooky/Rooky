/*
 * RenderImage.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERIMAGE_H_
#define SOURCE_CORE_RENDER_RENDERIMAGE_H_

#include "RenderResource.h"
#include "RenderFormat.h"
#include "RenderMath.h"
#include "RenderTypes.h"

namespace Render
{
class Image : public Resource
{
public:
	explicit Image(Context* context);
	virtual ~Image(void) override;

public:
	virtual void Create(Format format, const Extent3& extent, uint32_t usage) = 0;
	virtual void CreateView(ImageType type) = 0;

public:
	inline ImageType GetType(void) const { return mType; }
	inline Format GetFormat(void) const { return mFormat; }
	inline const Extent3& GetExtent(void) const { return mExtent; }

protected:
	Extent3 mExtent = {};

protected:
	Format mFormat = Format::FORMAT_UNDEFINED;
	ImageType mType = ImageType::IMAGE_TYPE_UNKNOWN;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERIMAGE_H_ */
