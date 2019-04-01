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
#include "RenderPipelineCommon.h"
#include "State/RenderDescription.h"

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
	inline void SetShaderState(ShaderState* state) { mShaderState = state;  }
	inline void SetVertexLayout(VertexLayout* layout) { mVertexLayout = layout; }
	inline void SetRenderPass(uint32_t index, Pass* pass)
	{
		mIndex = index;
		mRenderPass = pass;
	}

public:
	inline uint32_t GetSubIndex(void) const { return mIndex; }
	inline Pass* GetRenderPass(void) const { return mRenderPass; }
	inline PipelineLayout* GetLayout(void) const { return mPipelineLayout; }
	inline VertexLayout* GetVertexLayout(void) const { return mVertexLayout; }

public:
	inline const ShaderState* GetShaderState(void) const { return mShaderState; }
	inline const PipelineCommon* GetCommon(void) const { return &mPipelineCommon; }

protected:
	uint32_t mIndex = 0;
	Pass* mRenderPass = nullptr;
	ShaderState* mShaderState = nullptr;
	VertexLayout* mVertexLayout = nullptr;
	PipelineLayout* mPipelineLayout = nullptr;

protected:
	PipelineCommon mPipelineCommon = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINESTATE_H_ */
