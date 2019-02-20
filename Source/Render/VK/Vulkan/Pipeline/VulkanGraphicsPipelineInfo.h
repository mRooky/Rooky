/*
 * VKGraphicsPipelineInfo.h
 *
 *  Created on: Feb 20, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANGRAPHICSPIPELINEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANGRAPHICSPIPELINEINFO_H_

#include "VulkanPipelineStateInterfaces.h"

namespace Vulkan
{
class RenderPass;
class PipelineLayout;
class GraphicsPipelineInfo: public VkGraphicsPipelineCreateInfo
{
public:
	GraphicsPipelineInfo(void);
	~GraphicsPipelineInfo(void);

public:
	void SetContent(PipelineLayout* layout, RenderPass* pass, uint32_t index);

public:
	inline ShaderStageInfo* GetShaderStageInfo(void) { return &mShaderStage; }
	inline VertexInputStateInfo* GetVertexInputStateInfo(void) { return &mVertexInputState; }
	inline InputAssemblyStateInfo* GetInputAssemblyStateInfo(void) { return &mInputAssemblyState; }
	inline ViewportStateInfo* GetViewportStateInfo(void) { return &mViewportState; }
	inline RasterizationStateInfo* GetRasterizationStateInfo(void) { return &mRasterizationState; }
	inline MultisampleStateInfo* GetMultisampleStateInfo(void) { return &mMultisampleState; }
	inline DepthStencilStateInfo* GetDepthStencilStateInfo(void) { return &mDepthStencilState; }
	inline ColorBlendStateInfo* GetColorBlendStateInfo(void) { return &mColorBlendState; }
	inline DynamicStateInfo* GetDynamicStateInfo(void) { return &mDynamicState; }

protected:
	ShaderStageInfo mShaderStage;
	VertexInputStateInfo mVertexInputState;
	InputAssemblyStateInfo mInputAssemblyState;
	ViewportStateInfo mViewportState;
	RasterizationStateInfo mRasterizationState ;
	MultisampleStateInfo mMultisampleState;
	DepthStencilStateInfo mDepthStencilState;
	ColorBlendStateInfo mColorBlendState;
	DynamicStateInfo mDynamicState;

protected:

};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANGRAPHICSPIPELINEINFO_H_ */
