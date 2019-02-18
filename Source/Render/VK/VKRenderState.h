/*
 * VKRenderState.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRENDERSTATE_H_
#define SOURCE_RENDER_VK_VKRENDERSTATE_H_

#include "RenderState.h"
#include "VKRender.h"
#include "VKPipelineState.h"

namespace VK
{
class Context;
class RenderState: public Render::State
{
public:
	explicit RenderState(Context* context);
	virtual ~RenderState(void) override;

public:
	void CreateCache(void);
	void CreateLayout(void);

public:
	inline Vulkan::PipelineCache* GetCache(void) const { return m_pipelineCache; }
	inline Vulkan::PipelineLayout* GetLayout(void) const { return  m_pipelineLayout; }

public:
	VkGraphicsPipelineCreateInfo GetGraphicsCreateInfo(void) const;

private:
	Vulkan::PipelineCache* m_pipelineCache = nullptr;
	Vulkan::PipelineLayout* m_pipelineLayout = nullptr;

private:
	std::vector<Vulkan::DescriptorSetLayout*> m_descriptorSetLayouts;

private:
	InputAssemblyStateInfo m_inputAssemblyState = {};
	RasterizationStateInfo m_rasterizationState = {};
	ColorBlendStateInfo m_colorBlendState = {};
	ViewportStateInfo m_viewportState = {};
	DynamicStateInfo m_dynamicState = {};
	DepthStencilStateInfo m_depthStencilState = {};
	MultisampleStateInfo m_multisampleState = {};
	VertexInputStateInfo m_vertexInputState = {};

private:
	std::vector<ShaderStageInfo> m_shaderStages;

private:
	std::vector<VkPushConstantRange> m_constantRanges;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRENDERSTATE_H_ */
