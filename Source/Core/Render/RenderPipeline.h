/*
 * RenderPipeline.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINE_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINE_H_

#include "RenderObject.h"
#include <cstdint>

namespace Render
{
class Pass;
class Declaration;
class PipelineState;
class PipelineLayout;
class ShaderState;
class VertexLayout;
class Pipeline : public Object
{
public:
	explicit Pipeline(Device* device);
	virtual ~Pipeline(void) override;

public:
	virtual void Create(PipelineLayout* pipe_layout, VertexLayout* vert_layout, Pass* pass, uint32_t index) = 0;

public:
	bool IsValid(void) const;

public:
	inline uint32_t GetSubIndex(void) const { return mIndex; }
	inline Pass* GetRenderPass(void) const { return mRenderPass; }
	inline PipelineState* GetState(void) const { return mPipelineState; }
	inline ShaderState* GetShaderState(void) const { return mShaderState; }
	inline PipelineLayout* GetLayout(void) const { return mPipelineLayout; }

protected:
	uint32_t mIndex = 0;
	Pass* mRenderPass = nullptr;
	VertexLayout* mVertexLayout = nullptr;
	PipelineState* mPipelineState = nullptr;
	PipelineLayout* mPipelineLayout = nullptr;

public:
	ShaderState* mShaderState =nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINE_H_ */
