/*
 * RenderImage.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERIMAGE_H_
#define SOURCE_CORE_GHI_RENDERIMAGE_H_

#include "GHIImageLayout.h"
#include "GHIMemory.h"
#include "State/GHIColorBlend.h"

namespace GHI
{

class Buffer;
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
	virtual void Upload(uint32_t layer, uint32_t level, const void* src) = 0;

public:
	virtual void Update(Buffer* buffer) = 0;
	virtual void Update(uint32_t layer, uint32_t level, Buffer* buffer) = 0;

public:
	bool IsDepthStencil(void) const;
	size_t GetLevelOffset(uint32_t level) const;
	Math::Extent3Di GetLevelExtent(uint32_t level) const;

public:
	inline void SetClearColor(uint32_t color)
	{
		mLayout.SetClearColor(color);
	}

	inline void SetColorBlend(const ColorBlend& blend)
	{
		mColorBlend = blend;
	}

public:
	inline const ImageLayout& GetLayout(void) const
	{
		return mLayout;
	}

	inline const ColorBlend& GetColorBlend(void) const
	{
		return mColorBlend;
	}

protected:
	ImageLayout mLayout = {};
	ColorBlend mColorBlend = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERIMAGE_H_ */
