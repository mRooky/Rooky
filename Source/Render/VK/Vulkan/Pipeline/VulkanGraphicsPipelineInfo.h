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
class GraphicsPipelineInfo
{
public:
	GraphicsPipelineInfo(void);
	~GraphicsPipelineInfo(void);

public:
	void SetContent(PipelineLayout* layout, RenderPass* pass, uint32_t index);
	ShaderStageInfo* CreateShaderStage(void);

public:
	inline VertexInputStateInfo* GetVertexInputStateInfo(void) { return &mVertexInputState; }
	inline InputAssemblyStateInfo* GetInputAssemblyStateInfo(void) { return &mInputAssemblyState; }
	inline ViewportStateInfo* GetViewportStateInfo(void) { return &mViewportState; }
	inline RasterizationStateInfo* GetRasterizationStateInfo(void) { return &mRasterizationState; }
	inline MultisampleStateInfo* GetMultisampleStateInfo(void) { return &mMultisampleState; }
	inline DepthStencilStateInfo* GetDepthStencilStateInfo(void) { return &mDepthStencilState; }
	inline ColorBlendStateInfo* GetColorBlendStateInfo(void) { return &mColorBlendState; }
	inline DynamicStateInfo* GetDynamicStateInfo(void) { return &mDynamicState; }

public:
	inline size_t GetShaderStageCount(void) { return mShaderStages.size(); }
	inline const ShaderStageInfo& GetShaderStageInfo(size_t index) { return mShaderStages.at(index); }
	inline const VkGraphicsPipelineCreateInfo* CreateInfo(void) const { return &m_createInfo; }

protected:
	VertexInputStateInfo mVertexInputState;
	InputAssemblyStateInfo mInputAssemblyState;
	ViewportStateInfo mViewportState;
	RasterizationStateInfo mRasterizationState ;
	MultisampleStateInfo mMultisampleState;
	DepthStencilStateInfo mDepthStencilState;
	ColorBlendStateInfo mColorBlendState;
	DynamicStateInfo mDynamicState;

protected:
	std::vector<ShaderStageInfo> mShaderStages;

private:
	VkGraphicsPipelineCreateInfo m_createInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANGRAPHICSPIPELINEINFO_H_ */
