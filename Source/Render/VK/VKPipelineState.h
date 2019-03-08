/*
 * VKPipelineState.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKPIPELINESTATE_H_
#define SOURCE_RENDER_VK_VKPIPELINESTATE_H_

#include "RenderPipelineState.h"
#include "VKRender.h"
#include "Pipeline/VulkanGraphicsPipelineInfo.h"

namespace VK
{
class Context;
class PipelineState : public Render::PipelineState
{
public:
	explicit PipelineState(Context* context);
	virtual ~PipelineState(void) override;

public:
	virtual void Initialize(void) override;

public:
	inline Vulkan::GraphicsPipelineInfo* GetGraphicsInfo(void) { return &mGraphicsInfo; }

protected:
	Vulkan::GraphicsPipelineInfo mGraphicsInfo;
};

static inline PipelineState* StaticCast(Render::PipelineState* state)
{
	return static_cast<PipelineState*>(state);
}

static inline PipelineState* SaftyCast(Render::PipelineState* state)
{
	return dynamic_cast<PipelineState*>(state);
}

}

#endif /* SOURCE_RENDER_VK_VKPIPELINESTATE_H_ */
