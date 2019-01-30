/*
 * RenderState.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSTATE_H_
#define SOURCE_CORE_RENDER_RENDERSTATE_H_

#include "RenderObject.h"
#include <cstdint>

namespace Render
{

class State : public Object
{

public:
	enum class Blend : uint32_t
	{
		ZERO,
		ONE,
		SRC_COLOR,
		ONE_MINUS_SRC_COLOR,
		DST_COLOR,
		ONE_MINUS_DST_COLOR,
		SRC_ALPHA,
		ONE_MINUS_SRC_ALPHA,
		DST_ALPHA,
		ONE_MINUS_DST_ALPHA,
		CONSTANT_ALPHA,
		ONE_MINUS_CONSTANT_ALPHA,
		SRC_ALPHA_SATURATE
	};

    enum class DepthFunction : uint32_t
	{
		NEVER,
		LESS,
		EQUAL,
		LEQUAL,
		GREATER,
		NOTEQUAL,
		GEQUAL,
		ALWAYS
	};

	enum class CullFaceSide : uint32_t
	{
		BACK,
		FRONT,
		FRONT_AND_BACK
	};

	enum class FrontFace : uint32_t
	{
		CW,
		CCW
	};

	enum class StencilFunction : uint32_t
	{
		NEVER,
		ALWAYS,
		LESS,
		LEQUAL,
		EQUAL,
		GREATER,
		GEQUAL,
		NOTEQUAL
	};

	enum class StencilOperation : uint32_t
	{
		KEEP,
		ZERO,
		REPLACE,
		INCR,
		DECR,
		INVERT,
		INCR_WRAP,
		DECR_WRAP
	};

public:
	explicit State(Context* context);
	virtual ~State(void) override;

protected:
	bool mCullFaceEnabled = false;
	bool mDepthTestEnabled = true;
	bool mDepthWriteEnabled = true;
	bool mBlendEnabled = true;
	bool mStencilTestEnabled = false;
	uint32_t mStencilWrite = 0;
	uint32_t mStencilFunctionMask = 0;

protected:
	Blend mBlendSrc = Blend::SRC_ALPHA;
	Blend mBlendDst = Blend::ONE_MINUS_SRC_ALPHA;
	DepthFunction mDepthFunction = DepthFunction::LEQUAL;
	CullFaceSide mCullFaceSide = CullFaceSide::FRONT_AND_BACK;
	FrontFace mFrontFace = FrontFace::CW;
	StencilFunction mStencilFunction = StencilFunction::LEQUAL;
	StencilOperation mStencilOpSfail = StencilOperation::KEEP;
	StencilOperation mStencilOpDpfail = StencilOperation::KEEP;
	StencilOperation mStencilOpDppass = StencilOperation::KEEP;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSTATE_H_ */
