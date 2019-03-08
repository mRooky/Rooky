/*
 * RenderPepelineDescriptor.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINETRAITS_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINETRAITS_H_

#include "RenderShaderState.h"

namespace Render
{
class Pass;
class Declaration;
class PipelineState;
class PipelineLayout;
class PipelineTraits
{
public:
	PipelineTraits(void);
	~PipelineTraits(void);

public:
	bool IsValid(void) const;

public:
	bool operator == (const PipelineTraits& other) const;
	PipelineTraits& operator = (const PipelineTraits& other);

public:
	uint32_t index = 0;
	ShaderState shaderState;
	Pass* pRenderPass = nullptr;
	PipelineState* pPipelineState = nullptr;
	PipelineLayout* pPipelineLayout = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINETRAITS_H_ */
