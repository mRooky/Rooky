/*
 * CorePipelineState.h
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINESTATE_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINESTATE_H_

#include "RenderObject.h"
#include "RenderShaderState.h"
#include "RenderMultisample.h"
#include "RenderDepthStencil.h"
#include "RenderInputAssembly.h"
#include "RenderRasterization.h"
#include "RenderBlendState.h"

namespace Render
{
class Pass;
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
	inline void SetVertexLayout(VertexLayout* layout) { mVertexLayout = layout; }
	inline void SetRenderPass(uint32_t index, Pass* pass)
	{
		mIndex = index;
		mRenderPass = pass;
	}

public:
	inline uint32_t GetSubIndex(void) const { return mIndex; }
	inline Pass* GetRenderPass(void) const { return mRenderPass; }
	inline BlendState* GetBlendState(void) { return &mBlendState; }
	inline PipelineLayout* GetLayout(void) const { return mPipelineLayout; }
	inline VertexLayout* GetVertexLayout(void) const { return mVertexLayout; }

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
	Pass* mRenderPass = nullptr;
	VertexLayout* mVertexLayout = nullptr;
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

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINESTATE_H_ */
