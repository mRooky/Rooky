/*
 * RenderPipelineCommon.h
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINECOMMON_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINECOMMON_H_

#include "RenderMultisample.h"
#include "RenderRasterization.h"
#include "RenderInputAssembly.h"
#include <vector>

namespace Render
{

class PipelineCommon
{
public:
	PipelineCommon(void);
	virtual ~PipelineCommon(void);

public:
	bool operator==(const PipelineCommon& other) const;

public:
	inline void SetMultisample(const Multisample& multi) { mMultisample = multi; }
	inline void SetRasterization(const Rasterization& raster) { mRasterization = raster; }
	inline void SetInputAssembly(const InputAssembly& assembly) { mInputAssembly = assembly; }

public:
	inline const Multisample& GetMultisample(void) const { return mMultisample; }
	inline const InputAssembly& GetInputAssembly(void) const { return mInputAssembly; }
	inline const Rasterization& GetRasterization(void) const { return mRasterization; }

protected:
	Multisample mMultisample = {};
	InputAssembly mInputAssembly = {};
	Rasterization mRasterization = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINECOMMON_H_ */
