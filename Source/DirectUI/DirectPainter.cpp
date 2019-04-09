/*
 * DirectPainter.cpp
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#include "DirectContext.h"
#include "DirectPainter.h"
#include "DirectSurface.h"
#include "DirectVertex.h"
#include "DirectWindow.h"
#include "VulkanShaderModule.h"
#include "VulkanPipeline.h"
#include "VulkanPipelineCache.h"
#include "VulkanPipelineLayout.h"
#include "VulkanRenderPass.h"
#include "VulkanDescriptorSetLayout.h"
#include "VulkanInline.h"
#include <algorithm>
#include <cassert>

namespace Direct
{

Painter::Painter(Surface* surface)
{
	assert(m_parent != nullptr);
	m_parent = surface;
}

Painter::~Painter(void)
{
	m_parent = nullptr;
	Vulkan::Release(m_vertShader);
	Vulkan::Release(m_fragShader);
	Vulkan::Release(m_pipeline);
	Vulkan::Release(m_pipelineCache);
	Vulkan::Release(m_pipelineLayout);
	m_descriptorSetLayouts.clear();
}

void Painter::Create(std::vector<Vulkan::DescriptorSetLayout*> layouts)
{
	m_descriptorSetLayouts.reserve(layouts.size());
	for (auto layout : layouts)
	{
		m_descriptorSetLayouts.push_back(layout);
	}
	CreatePipelineLayout();
	CreatePipelineCache();
	CreatePipeline();
}

void Painter::CreatePipelineLayout(void)
{
	assert(m_descriptorSetLayouts.size() > 0);
	Vulkan::Device* device = Context::GetContext()->GetDevice();
	m_pipelineLayout = Vulkan::PipelineLayout::New(device);
	m_pipelineLayout->Create(m_descriptorSetLayouts);
}

void Painter::CreatePipelineCache(void)
{
	Vulkan::Device* device = Context::GetContext()->GetDevice();
	m_pipelineCache = Vulkan::PipelineCache::New(device);
	m_pipelineCache->Create(0, nullptr);
}

void Painter::CreatePipeline(void)
{
	assert(m_pipelineLayout != nullptr && m_pipelineCache != nullptr);

	std::vector<VkVertexInputBindingDescription> vertex_input_bindings;
	{
		vertex_input_bindings.push_back(Vertex::GetInputBindingDescription());
	}

	std::vector<VkVertexInputAttributeDescription> vertex_input_attributes = Vertex::GetInputAttributeDescriptions();

	auto vertex_input_state = Vulkan::Pipeline::VertexInputStateCreateInfo();
	vertex_input_state.vertexBindingDescriptionCount = vertex_input_bindings.size();
	vertex_input_state.pVertexBindingDescriptions = vertex_input_bindings.data();
	vertex_input_state.vertexAttributeDescriptionCount = vertex_input_attributes.size();
	vertex_input_state.pVertexAttributeDescriptions = vertex_input_attributes.data();

	auto input_assembly_state = Vulkan::Pipeline::InputAssemblyStateCreateInfo();
	input_assembly_state.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;

	auto rasterization_state = Vulkan::Pipeline::RasterizationStateCreateInfo();
	rasterization_state.polygonMode = VK_POLYGON_MODE_FILL;
	//m_rasterizationState.polygonMode = VK_POLYGON_MODE_LINE;
	rasterization_state.cullMode = VK_CULL_MODE_NONE;
	rasterization_state.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
	rasterization_state.depthClampEnable = VK_FALSE;
	rasterization_state.rasterizerDiscardEnable = VK_FALSE;
	rasterization_state.depthBiasEnable = VK_FALSE;
	rasterization_state.lineWidth = 1.0f;

	std::vector<VkPipelineColorBlendAttachmentState> blend_attachment_states;
	{
		VkPipelineColorBlendAttachmentState blend_attachment_state = {};
		blend_attachment_state.colorWriteMask = 0xf;
		blend_attachment_state.blendEnable = VK_FALSE;
		blend_attachment_states.push_back(blend_attachment_state);
	}

	auto color_blend_state = Vulkan::Pipeline::ColorBlendStateCreateInfo();
	color_blend_state.attachmentCount = blend_attachment_states.size();
	color_blend_state.pAttachments = blend_attachment_states.data();

	auto multisample_state = Vulkan::Pipeline::MultisampleStateCreateInfo();
	multisample_state.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
	multisample_state.pSampleMask = nullptr;

	auto viewport_state = Vulkan::Pipeline::ViewportStateCreateInfo();
	viewport_state.viewportCount = 1;
	viewport_state.scissorCount = 1;

	auto depth_stencil_state = Vulkan::Pipeline::DepthStencilStateCreateInfo();
	depth_stencil_state.depthTestEnable = VK_TRUE;
	depth_stencil_state.depthWriteEnable = VK_TRUE;
	depth_stencil_state.depthCompareOp = VK_COMPARE_OP_LESS_OR_EQUAL;
	depth_stencil_state.depthBoundsTestEnable = VK_FALSE;
	depth_stencil_state.back.failOp = VK_STENCIL_OP_KEEP;
	depth_stencil_state.back.passOp = VK_STENCIL_OP_KEEP;
	depth_stencil_state.back.compareOp = VK_COMPARE_OP_ALWAYS;
	depth_stencil_state.stencilTestEnable = VK_FALSE;
	depth_stencil_state.front = depth_stencil_state.back;

	std::vector<VkDynamicState> dynamic_state_enables;
	dynamic_state_enables.push_back(VK_DYNAMIC_STATE_VIEWPORT);
	dynamic_state_enables.push_back(VK_DYNAMIC_STATE_SCISSOR);

	auto dynamic_state = Vulkan::Pipeline::DynamicStateCreateInfo();
	dynamic_state.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
	dynamic_state.dynamicStateCount = dynamic_state_enables.size();
	dynamic_state.pDynamicStates = dynamic_state_enables.data();

	VkGraphicsPipelineCreateInfo pipeline_create_info = Vulkan::Pipeline::GraphicsCreateInfo();

	pipeline_create_info.pVertexInputState = &vertex_input_state;
	pipeline_create_info.pInputAssemblyState = &input_assembly_state;
	pipeline_create_info.pRasterizationState = &rasterization_state;
	pipeline_create_info.pColorBlendState = &color_blend_state;
	pipeline_create_info.pMultisampleState = &multisample_state;
	pipeline_create_info.pViewportState = &viewport_state;
	pipeline_create_info.pDepthStencilState = &depth_stencil_state;
	pipeline_create_info.pDynamicState = &dynamic_state;

	std::vector<VkPipelineShaderStageCreateInfo> shader_stages =
	{
		m_vertShader->GetStageInfo(VK_SHADER_STAGE_VERTEX_BIT),
		m_fragShader->GetStageInfo(VK_SHADER_STAGE_FRAGMENT_BIT)
	};

	pipeline_create_info.stageCount = shader_stages.size();
	pipeline_create_info.pStages = shader_stages.data();

	assert(m_parent != nullptr);
	auto render_pass = m_parent->GetRenderPass();
	pipeline_create_info.renderPass = render_pass->GetHandle();
	pipeline_create_info.layout = m_pipelineLayout->GetHandle();

	Vulkan::Device* device = Context::GetContext()->GetDevice();
	m_pipeline = Vulkan::Pipeline::New(device);
	m_pipeline->Create(m_pipelineCache, &pipeline_create_info);
}

void Painter::Binding(Vulkan::CommandBuffer* buffer)
{
	assert(buffer != nullptr);
	assert(false);
}

} /* namespace Direct */
