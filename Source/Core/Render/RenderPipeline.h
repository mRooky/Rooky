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
class State;
class Pipeline
{
public:
	explicit Pipeline(Pass* pass);
	virtual ~Pipeline(void);

public:
	virtual void Initialize(State* state, uint32_t index) = 0;

public:
	inline uint32_t GetIndex(void) const { return mIndex; }
	inline Pass* GetRenderPass(void) const { return mRenderPass; }
	inline State* GetRenderState(void) const { return mRenderState; }

protected:
	uint32_t mIndex = 0;
	Pass* mRenderPass = nullptr;
	State* mRenderState = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINE_H_ */
