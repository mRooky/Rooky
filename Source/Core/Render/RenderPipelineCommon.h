/*
 * RenderPipelineCommon.h
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINECOMMON_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINECOMMON_H_

#include "State/RenderDescription.h"
#include <vector>

namespace Render
{

class PipelineCommon
{
public:
	PipelineCommon(void);
	virtual ~PipelineCommon(void);

public:
	inline size_t GetColorBlendCount(void) const { return mColorBlends.size(); }
	inline void SetColorBlend(const ColorBlend& blend) { mColorBlends.push_back(blend); }
	inline const ColorBlend& GetColorBlend(size_t index) const { return mColorBlends.at(index); }

public:
	inline void SetMultisample(const Multisample& multi) { mMultisample = multi; }
	inline void SetDepthStencil(const DepthStencil& depth) { mDepthStencil = depth; }
	inline void SetRasterization(const Rasterization& raster) { mRasterization = raster; }
	inline void SetInputAssembly(const InputAssembly& assembly) { mInputAssembly = assembly; }

public:
	inline const Multisample& GetMultisample(void) const { return mMultisample; }
	inline const DepthStencil& GetDepthStencil(void) const { return mDepthStencil; }
	inline const InputAssembly& GetInputAssembly(void) const { return mInputAssembly; }
	inline const Rasterization& GetRasterization(void) const { return mRasterization; }

protected:
	std::vector<ColorBlend> mColorBlends = {};

protected:
	Multisample mMultisample = {};
	DepthStencil mDepthStencil = {};
	InputAssembly mInputAssembly = {};
	Rasterization mRasterization = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINECOMMON_H_ */
