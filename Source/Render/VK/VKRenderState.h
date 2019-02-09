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
	VkPipelineInputAssemblyStateCreateInfo m_inputAssemblyState = {};
	VkPipelineRasterizationStateCreateInfo m_rasterizationState = {};
	VkPipelineColorBlendStateCreateInfo m_colorBlendState = {};
	VkPipelineViewportStateCreateInfo m_viewportState = {};
	VkPipelineDynamicStateCreateInfo m_dynamicState = {};
	VkPipelineDepthStencilStateCreateInfo m_depthStencilState = {};
	VkPipelineMultisampleStateCreateInfo m_multisampleState = {};
	VkPipelineVertexInputStateCreateInfo m_vertexInputState = {};

private:
	std::vector<VkPipelineColorBlendAttachmentState> m_blendAttachmentStates;
	std::vector<VkDynamicState> m_dynamicStateEnables;
	std::vector<VkVertexInputBindingDescription> m_vertexInputBindings;
	std::vector<VkVertexInputAttributeDescription> m_vertexInputAttributes;
	std::vector<VkPipelineShaderStageCreateInfo> m_shaderStages;

private:
	std::vector<VkPushConstantRange> m_constantRanges;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRENDERSTATE_H_ */
