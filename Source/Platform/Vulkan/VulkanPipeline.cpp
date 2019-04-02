/*
 * VulkanPipeline.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanPipeline.h"
#include "VulkanDevice.h"
#include "VulkanPipelineCache.h"
#include "VulkanInline.h"
#include <cassert>

namespace Vulkan
{

Pipeline::Pipeline(Device* device):
		DeviceObject(device)
{
}

Pipeline::~Pipeline(void)
{
	Vulkan::Release(m_cache);
	VkDevice device = mDevice->GetHandle();
	vkDestroyPipeline(device, m_pipeline, nullptr);
	m_pipeline = VK_NULL_HANDLE;
	m_layout = VK_NULL_HANDLE;
}

VkResult Pipeline::Create(const PipelineCache* cache, const VkComputePipelineCreateInfo* info)
{
	assert(false);
	return VK_INCOMPLETE;
}

VkResult Pipeline::Create(const PipelineCache* cache, const VkGraphicsPipelineCreateInfo* info)
{
	assert(m_pipeline == VK_NULL_HANDLE);
	CreateCache(cache);
	auto device = mDevice->GetHandle();
	m_point = VK_PIPELINE_BIND_POINT_GRAPHICS;
	auto pipeline_cache = m_cache->GetHandle();
	mResult = vkCreateGraphicsPipelines(device, pipeline_cache, 1, info, nullptr, &m_pipeline);
	assert(mResult == VK_SUCCESS);
	m_layout = info->layout;
	return mResult;
}

void Pipeline::CreateCache(const PipelineCache* cache)
{
	assert(m_cache == nullptr);
	m_cache = PipelineCache::New(mDevice);
	VkResult result = VK_INCOMPLETE;
	size_t size = 0;
	const void* data = nullptr;
	if (cache != nullptr)
	{
		size = cache->GetSize();
		data = cache->GetData();
	}
	result = m_cache->Create(size, data);
	assert(result == VK_SUCCESS);
}

VkPipelineShaderStageCreateInfo Pipeline::ShaderStageCreateInfo(void)
{
	VkPipelineShaderStageCreateInfo pipeline_shader_stage_create_info = {};
	pipeline_shader_stage_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	pipeline_shader_stage_create_info.pNext = nullptr;
	pipeline_shader_stage_create_info.pSpecializationInfo = nullptr;
	pipeline_shader_stage_create_info.flags = 0;
	pipeline_shader_stage_create_info.stage = VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM;
	pipeline_shader_stage_create_info.pName = "main";
	return pipeline_shader_stage_create_info;
}

VkPipelineDynamicStateCreateInfo Pipeline::DynamicStateCreateInfo(void)
{
	VkPipelineDynamicStateCreateInfo pipeline_dynamic_state_create_info = {};
	pipeline_dynamic_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
	pipeline_dynamic_state_create_info.pNext = nullptr;
	pipeline_dynamic_state_create_info.flags = 0;
	pipeline_dynamic_state_create_info.dynamicStateCount = 0;
	pipeline_dynamic_state_create_info.pDynamicStates = nullptr;
	return pipeline_dynamic_state_create_info;
}

VkPipelineVertexInputStateCreateInfo Pipeline::VertexInputStateCreateInfo(void)
{
	VkPipelineVertexInputStateCreateInfo pipeline_vertex_input_state_create_info = {};
	pipeline_vertex_input_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
	pipeline_vertex_input_state_create_info.pNext = nullptr;
	pipeline_vertex_input_state_create_info.flags = 0;
	pipeline_vertex_input_state_create_info.vertexBindingDescriptionCount = 0;
	pipeline_vertex_input_state_create_info.pVertexBindingDescriptions = nullptr;
	pipeline_vertex_input_state_create_info.vertexAttributeDescriptionCount = 0;
	pipeline_vertex_input_state_create_info.pVertexAttributeDescriptions = nullptr;
	return pipeline_vertex_input_state_create_info;
}

VkPipelineInputAssemblyStateCreateInfo Pipeline::InputAssemblyStateCreateInfo(void)
{
	VkPipelineInputAssemblyStateCreateInfo pipeline_input_assembly_state_create_info = {};
	pipeline_input_assembly_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
	pipeline_input_assembly_state_create_info.pNext = nullptr;
	pipeline_input_assembly_state_create_info.flags = 0;
	pipeline_input_assembly_state_create_info.primitiveRestartEnable = VK_FALSE;
	pipeline_input_assembly_state_create_info.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	return pipeline_input_assembly_state_create_info;
}

VkPipelineRasterizationStateCreateInfo Pipeline::RasterizationStateCreateInfo(void)
{
	VkPipelineRasterizationStateCreateInfo pipeline_rasterization_state_create_info = {};
	pipeline_rasterization_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
	pipeline_rasterization_state_create_info.pNext = nullptr;
	pipeline_rasterization_state_create_info.flags = 0;
	pipeline_rasterization_state_create_info.polygonMode = VK_POLYGON_MODE_FILL;
	pipeline_rasterization_state_create_info.cullMode = VK_CULL_MODE_NONE;
	pipeline_rasterization_state_create_info.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;
	pipeline_rasterization_state_create_info.depthClampEnable = VK_FALSE;
	pipeline_rasterization_state_create_info.rasterizerDiscardEnable = VK_FALSE;
	pipeline_rasterization_state_create_info.depthBiasEnable = VK_FALSE;
	pipeline_rasterization_state_create_info.depthBiasConstantFactor = 0;
	pipeline_rasterization_state_create_info.depthBiasClamp = 0;
	pipeline_rasterization_state_create_info.depthBiasSlopeFactor = 0;
	pipeline_rasterization_state_create_info.lineWidth = 1.0f;
	return pipeline_rasterization_state_create_info;
}

VkPipelineColorBlendStateCreateInfo Pipeline::ColorBlendStateCreateInfo(void)
{
	VkPipelineColorBlendStateCreateInfo pipeline_color_blend_state_create_info = {};
	pipeline_color_blend_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	pipeline_color_blend_state_create_info.pNext = nullptr;
	pipeline_color_blend_state_create_info.flags = 0;
	pipeline_color_blend_state_create_info.attachmentCount = 0;
	pipeline_color_blend_state_create_info.pAttachments = nullptr;
	pipeline_color_blend_state_create_info.blendConstants[0] = 1.0f;
	pipeline_color_blend_state_create_info.blendConstants[1] = 1.0f;
	pipeline_color_blend_state_create_info.blendConstants[2] = 1.0f;
	pipeline_color_blend_state_create_info.blendConstants[3] = 1.0f;
	pipeline_color_blend_state_create_info.logicOp = VK_LOGIC_OP_CLEAR;
	pipeline_color_blend_state_create_info.logicOpEnable = VK_FALSE;
	return pipeline_color_blend_state_create_info;
}

VkPipelineColorBlendAttachmentState Pipeline::ColorBlendAttachmentState(bool blend)
{
	VkPipelineColorBlendAttachmentState pipeline_color_blend_attachment_state = {};
	if (blend)
	{
		pipeline_color_blend_attachment_state.blendEnable = VK_TRUE;
		pipeline_color_blend_attachment_state.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
		pipeline_color_blend_attachment_state.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
		pipeline_color_blend_attachment_state.colorBlendOp = VK_BLEND_OP_ADD;
		pipeline_color_blend_attachment_state.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE;
		pipeline_color_blend_attachment_state.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
		pipeline_color_blend_attachment_state.alphaBlendOp = VK_BLEND_OP_ADD;
		pipeline_color_blend_attachment_state.colorWriteMask = VK_COLOR_COMPONENT_R_BIT
					| VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
	}
	else
	{
		pipeline_color_blend_attachment_state.blendEnable = VK_FALSE;
		pipeline_color_blend_attachment_state.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_COLOR;
		pipeline_color_blend_attachment_state.srcAlphaBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
		pipeline_color_blend_attachment_state.dstColorBlendFactor = VK_BLEND_FACTOR_DST_COLOR;
		pipeline_color_blend_attachment_state.dstAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
		pipeline_color_blend_attachment_state.colorBlendOp = VK_BLEND_OP_ADD;
		pipeline_color_blend_attachment_state.alphaBlendOp = VK_BLEND_OP_ADD;
		pipeline_color_blend_attachment_state.colorWriteMask = VK_COLOR_COMPONENT_R_BIT
							| VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
	}
	return pipeline_color_blend_attachment_state;
}

VkPipelineViewportStateCreateInfo Pipeline::ViewportStateCreateInfo(void)
{
	VkPipelineViewportStateCreateInfo pipeline_viewport_state_create_info = {};
	pipeline_viewport_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
	pipeline_viewport_state_create_info.pNext = nullptr;
	pipeline_viewport_state_create_info.flags = 0;
	pipeline_viewport_state_create_info.viewportCount = 1;
	pipeline_viewport_state_create_info.scissorCount = 1;
	pipeline_viewport_state_create_info.pScissors = nullptr;
	pipeline_viewport_state_create_info.pViewports = nullptr;
	return pipeline_viewport_state_create_info;
}

VkPipelineDepthStencilStateCreateInfo Pipeline::DepthStencilStateCreateInfo(void)
{
	VkPipelineDepthStencilStateCreateInfo pipeline_depth_stencil_state_create_info = {};
	pipeline_depth_stencil_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
	pipeline_depth_stencil_state_create_info.pNext = nullptr;
	pipeline_depth_stencil_state_create_info.flags = 0;
	pipeline_depth_stencil_state_create_info.depthTestEnable = VK_TRUE;
	pipeline_depth_stencil_state_create_info.depthWriteEnable = VK_TRUE;
	pipeline_depth_stencil_state_create_info.depthCompareOp = VK_COMPARE_OP_LESS_OR_EQUAL;
	pipeline_depth_stencil_state_create_info.depthBoundsTestEnable = VK_FALSE;
	pipeline_depth_stencil_state_create_info.stencilTestEnable = VK_FALSE;
	pipeline_depth_stencil_state_create_info.back.failOp = VK_STENCIL_OP_KEEP;
	pipeline_depth_stencil_state_create_info.back.passOp = VK_STENCIL_OP_KEEP;
	pipeline_depth_stencil_state_create_info.back.compareOp = VK_COMPARE_OP_ALWAYS;
	pipeline_depth_stencil_state_create_info.back.compareMask = 0;
	pipeline_depth_stencil_state_create_info.back.reference = 0;
	pipeline_depth_stencil_state_create_info.back.depthFailOp = VK_STENCIL_OP_KEEP;
	pipeline_depth_stencil_state_create_info.back.writeMask = 0;
	pipeline_depth_stencil_state_create_info.minDepthBounds = 0;
	pipeline_depth_stencil_state_create_info.maxDepthBounds = 0;
	pipeline_depth_stencil_state_create_info.front = pipeline_depth_stencil_state_create_info.back;
	return pipeline_depth_stencil_state_create_info;
}

VkPipelineMultisampleStateCreateInfo Pipeline::MultisampleStateCreateInfo(void)
{
	VkPipelineMultisampleStateCreateInfo pipeline_multisample_state_create_info = {};
	pipeline_multisample_state_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
	pipeline_multisample_state_create_info.pNext = nullptr;
	pipeline_multisample_state_create_info.flags = 0;
	pipeline_multisample_state_create_info.pSampleMask = nullptr;
	pipeline_multisample_state_create_info.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
	pipeline_multisample_state_create_info.sampleShadingEnable = VK_FALSE;
	pipeline_multisample_state_create_info.alphaToCoverageEnable = VK_FALSE;
	pipeline_multisample_state_create_info.alphaToOneEnable = VK_FALSE;
	pipeline_multisample_state_create_info.minSampleShading = 0.0;
	return pipeline_multisample_state_create_info;
}

VkGraphicsPipelineCreateInfo Pipeline::GraphicsCreateInfo(void)
{
	VkGraphicsPipelineCreateInfo graphics_pipeline_create_info = {};
	graphics_pipeline_create_info.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
	graphics_pipeline_create_info.pNext = nullptr;
	graphics_pipeline_create_info.layout = VK_NULL_HANDLE;
	graphics_pipeline_create_info.basePipelineHandle = VK_NULL_HANDLE;
	graphics_pipeline_create_info.basePipelineIndex = 0;
	graphics_pipeline_create_info.flags = 0;
	graphics_pipeline_create_info.pVertexInputState = nullptr;
	graphics_pipeline_create_info.pInputAssemblyState = nullptr;
	graphics_pipeline_create_info.pRasterizationState = nullptr;
	graphics_pipeline_create_info.pColorBlendState = nullptr;
	graphics_pipeline_create_info.pTessellationState = nullptr;
	graphics_pipeline_create_info.pMultisampleState = nullptr;
	graphics_pipeline_create_info.pDynamicState = nullptr;
	graphics_pipeline_create_info.pViewportState = nullptr;
	graphics_pipeline_create_info.pDepthStencilState = nullptr;
	graphics_pipeline_create_info.pStages = nullptr;
	graphics_pipeline_create_info.stageCount = 0;
	graphics_pipeline_create_info.renderPass = VK_NULL_HANDLE;
	graphics_pipeline_create_info.subpass = 0;
	return graphics_pipeline_create_info;
}


} /* namespace Vulkan */
