/*
 * RenderPepelineDescriptor.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPIPELINEDESCRIPTION_H_
#define SOURCE_CORE_RENDER_RENDERPIPELINEDESCRIPTION_H_

#include "RenderShaderState.h"

namespace Render
{
class Pass;
class Declaration;
class PipelineState;
class PipelineLayout;
class PipelineDescription
{
public:
	PipelineDescription(void);
	~PipelineDescription(void);

public:
	bool IsValid(void) const;

public:
	bool operator == (const PipelineDescription& other) const;
	PipelineDescription& operator = (const PipelineDescription& other);

public:
	uint32_t index = 0;
	ShaderState shaderState;
	Pass* pRenderPass = nullptr;
	PipelineState* pPipelineState = nullptr;
	PipelineLayout* pPipelineLayout = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINEDESCRIPTION_H_ */
