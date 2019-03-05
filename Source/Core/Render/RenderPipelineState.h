/*
 * CorePipelineState.h
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINESTATE_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINESTATE_H_

#include "RenderObject.h"
#include "RenderEnum.h"
#include <vector>

namespace Render
{
class Shader;
class Element;
class PipelineState : public Object
{
public:
	PipelineState(Context* context);
	virtual ~PipelineState(void) override;

protected:
	Element* mElement = nullptr;
	std::vector<Shader*> mShaders;

protected:
	bool mBlendEnabled = true;
	bool mCullFaceEnabled = false;
	bool mDepthTestEnabled = true;
	bool mDepthWriteEnabled = true;
	bool mStencilTestEnabled = false;

protected:
	uint32_t mStencilWrite = 0;
	uint32_t mStencilFunctionMask = 0;

protected:
	BlendFactor mBlendSrc = BlendFactor::BLEND_FACTOR_SRC_ALPHA;
	BlendFactor mBlendDst = BlendFactor::BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
	DepthFunction mDepthFunction = DepthFunction::DEPTH_FUNCTION_LEQUAL;
	CullFaceSide mCullFaceSide = CullFaceSide::CULL_FACE_SIDE_FRONT_AND_BACK;
	FrontFace mFrontFace = FrontFace::FRONT_FACE_CW;
	StencilFunction mStencilFunction = StencilFunction::STENCIL_FUNCTION_LEQUAL;
	StencilOperation mStencilOpSfail = StencilOperation::STENCIL_OPERATION_KEEP;
	StencilOperation mStencilOpDpfail = StencilOperation::STENCIL_OPERATION_KEEP;
	StencilOperation mStencilOpDppass = StencilOperation::STENCIL_OPERATION_KEEP;
};

} /* namespace Core */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINESTATE_H_ */
