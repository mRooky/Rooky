/*
 * CorePipelineState.h
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERPIPELINESTATE_H_
#define SOURCE_CORE_GHI_RENDERPIPELINESTATE_H_

#include "GHIObject.h"
#include "GHIShaderState.h"
#include "GHIBlendState.h"
#include "GHIDepthStencil.h"
#include "GHIInputAssembly.h"
#include "GHIMultisample.h"
#include "GHIRasterization.h"

namespace GHI
{
class RenderPass;
class PipelineLayout;
class VertexLayout;
class PipelineState
{
public:
	PipelineState(void);
	~PipelineState(void);

public:
	bool operator==(const PipelineState& other) const;

public:
	inline void SetLayout(PipelineLayout* layout) { mPipelineLayout = layout; }
	inline void SetRenderPass(uint32_t index, RenderPass* pass)
	{
		mIndex = index;
		mRenderPass = pass;
	}

public:
	inline uint32_t GetSubIndex(void) const { return mIndex; }
	inline RenderPass* GetRenderPass(void) const { return mRenderPass; }
	inline PipelineLayout* GetLayout(void) const { return mPipelineLayout; }

public:
	inline const BlendState& GetBlendState(void) { return mBlendState; }

public:
	inline void SetShaderState(const ShaderState& state) { mShaderState = state; }
	inline void SetMultisample(const Multisample& multi) { mMultisample = multi; }
	inline void SetDepthStencil(const DepthStencil& depth) { mDepthStencil = depth; }
	inline void SetRasterization(const Rasterization& raster) { mRasterization = raster; }
	inline void SetInputAssembly(const InputAssembly& assembly) { mInputAssembly = assembly; }

public:
	inline const Multisample& GetMultisample(void) const { return mMultisample; }
	inline const ShaderState& GetShaderState(void) const { return mShaderState; }
	inline const DepthStencil& GetDepthStencil(void) const { return mDepthStencil; }
	inline const InputAssembly& GetInputAssembly(void) const { return mInputAssembly; }
	inline const Rasterization& GetRasterization(void) const { return mRasterization; }

protected:
	uint32_t mIndex = 0;
	RenderPass* mRenderPass = nullptr;
	PipelineLayout* mPipelineLayout = nullptr;

protected:
	BlendState mBlendState = {};

protected:
	ShaderState mShaderState = {};
	DepthStencil mDepthStencil = {};
	Multisample mMultisample = {};
	InputAssembly mInputAssembly = {};
	Rasterization mRasterization = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_GHI_RENDERPIPELINESTATE_H_ */
