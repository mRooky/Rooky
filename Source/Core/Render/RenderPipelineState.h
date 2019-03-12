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
#include "State/RenderDescription.h"
#include <vector>

namespace Render
{

class PipelineState : public Object
{
public:
	PipelineState(Context* context);
	virtual ~PipelineState(void) override;

public:
	virtual void Initialize(void) = 0;

protected:
	ColorBlend mColorBlend = {};
	DepthStencil mDepthStencil = {};
	InputAssembly mInputAssembly = {};
	Multisample mMultisample = {};
	Rasterization mRasterization = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_RENDER_RENDERPIPELINESTATE_H_ */
