/*
 * RenderState.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSTATE_H_
#define SOURCE_CORE_RENDER_RENDERSTATE_H_

#include "RenderObject.h"
#include "RenderTypes.h"
#include <cstdint>
#include <vector>

namespace Render
{
class Shader;
class Element;
class State : public Object
{

public:
	explicit State(Context* context);
	virtual ~State(void) override;

protected:
	Element* mElement = nullptr;
	std::vector<Shader*> mShaders;

protected:
	bool mCullFaceEnabled = false;
	bool mDepthTestEnabled = true;
	bool mDepthWriteEnabled = true;
	bool mBlendEnabled = true;
	bool mStencilTestEnabled = false;
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

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSTATE_H_ */
