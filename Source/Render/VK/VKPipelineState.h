/*
 * VKPipelineState.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKPIPELINESTATE_H_
#define SOURCE_RENDER_VK_VKPIPELINESTATE_H_

#include "RenderState.h"

#include "Pipeline/VKPipelineStateInterfaces.h"

namespace VK
{
class Context;
class PipelineState : public Render::State
{
public:
	explicit PipelineState(Context* context);
	virtual ~PipelineState(void) override;

public:
	VkGraphicsPipelineCreateInfo GetGraphicsCreateInfo(void) const;

public:
	inline DynamicStateInfo* GetDynamicStateInfo(void) { return &mDynamicState; }
	inline ViewportStateInfo* GetViewportStateInfo(void) { return &mViewportState; }
	inline ColorBlendStateInfo* GetColorBlendStateInfo(void) { return &mColorBlendState; }
	inline MultisampleStateInfo* GetMultisampleStateInfo(void) { return &mMultisampleState; }
	inline VertexInputStateInfo* GetVertexInputStateInfo(void) { return &mVertexInputState; }
	inline DepthStencilStateInfo* GetDepthStencilStateInfo(void) { return &mDepthStencilState; }
	inline InputAssemblyStateInfo* GetInputAssemblyStateInfo(void) { return &mInputAssemblyState; }
	inline RasterizationStateInfo* GetRasterizationStateInfo(void) { return &mRasterizationState; }

protected:
	DynamicStateInfo mDynamicState = {};
	ViewportStateInfo mViewportState = {};
	ColorBlendStateInfo mColorBlendState = {};
	MultisampleStateInfo mMultisampleState = {};
	VertexInputStateInfo mVertexInputState = {};
	DepthStencilStateInfo mDepthStencilState = {};
	InputAssemblyStateInfo mInputAssemblyState = {};
	RasterizationStateInfo mRasterizationState = {};

protected:
	std::vector<ShaderStageInfo> m_shaderStages;
	std::vector<VkPushConstantRange> m_constantRanges;
};

}

#endif /* SOURCE_RENDER_VK_VKPIPELINESTATE_H_ */
