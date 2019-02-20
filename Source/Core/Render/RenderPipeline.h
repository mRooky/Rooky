/*
 * RenderPipeline.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINE_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINE_H_

#include <cstdint>

namespace Render
{
class Pass;
class PipelineState;
class Pipeline
{
public:
	explicit Pipeline(PipelineState* state);
	virtual ~Pipeline(void);

public:
	virtual void Initialize(Pass* pass, uint32_t index) = 0;

public:
	inline uint32_t GetIndex(void) const { return mIndex; }
	inline Pass* GetRenderPass(void) const { return mRenderPass; }
	inline PipelineState* GetPipelineState(void) const { return mPipelineState; }

protected:
	uint32_t mIndex = 0;

protected:
	Pass* mRenderPass = nullptr;
	PipelineState* mPipelineState = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINE_H_ */
