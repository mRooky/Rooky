/*
 * RenderImage.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERIMAGE_H_
#define SOURCE_CORE_GHI_RENDERIMAGE_H_

#include "GHIImageLayout.h"
#include "MathColor.h"
#include "GHIMemory.h"
#include "GHIColorBlend.h"

namespace GHI
{
class SwapChain;
class Image : public Memory
{
protected:
	explicit Image(Device* device);

public:
	virtual ~Image(void) override;

public:
	virtual void Create(const ImageLayout& layout, const UsageType& usage) = 0;

public:
	virtual void Download(void* dst) = 0;
	virtual void Upload(uint32_t index, uint32_t mipmap, const void* src) = 0;

public:
	inline void SetClearColor(uint32_t color) { mLayout.SetClearColor(color); }

public:
	inline const ImageLayout& GetLayout(void) { return mLayout; }
	inline ColorBlend* GetColorBlend(void) { return &mColorBlend; }

public:
	static bool IsDepthStencilFormat(Format format);

protected:
	ImageLayout mLayout = {};
	ColorBlend mColorBlend = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERIMAGE_H_ */
