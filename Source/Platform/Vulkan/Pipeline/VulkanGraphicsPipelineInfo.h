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
	VkPipelineShaderStageCreateInfo* CreateShaderStage(void);

public:
	void SetContent(PipelineLayout* layout);
	void SetContent(RenderPass* pass, uint32_t index);

public:
	inline VertexInputStateInfo* GetVertexInputStateInfo(void) { return &mVertexInputStateInfo; }
	inline InputAssemblyStateInfo* GetInputAssemblyStateInfo(void) { return &mInputAssemblyStateInfo; }
	inline ViewportStateInfo* GetViewportStateInfo(void) { return &mViewportStateInfo; }
	inline RasterizationStateInfo* GetRasterizationStateInfo(void) { return &mRasterizationStateInfo; }
	inline MultisampleStateInfo* GetMultisampleStateInfo(void) { return &mMultisampleStateInfo; }
	inline DepthStencilStateInfo* GetDepthStencilStateInfo(void) { return &mDepthStencilStateInfo; }
	inline ColorBlendStateInfo* GetColorBlendStateInfo(void) { return &mColorBlendStateInfo; }
	inline DynamicStateInfo* GetDynamicStateInfo(void) { return &mDynamicStateInfo; }

public:
	inline size_t GetShaderStageCount(void) { return mShaderStages.size(); }
	inline const VkPipelineShaderStageCreateInfo& GetShaderStageInfo(size_t index) { return mShaderStages.at(index); }

public:
	inline const VkGraphicsPipelineCreateInfo* CreateInfo(void) const { return &m_createInfo; }

protected:
	VertexInputStateInfo mVertexInputStateInfo;
	InputAssemblyStateInfo mInputAssemblyStateInfo;
	ViewportStateInfo mViewportStateInfo;
	RasterizationStateInfo mRasterizationStateInfo;
	MultisampleStateInfo mMultisampleStateInfo;
	DepthStencilStateInfo mDepthStencilStateInfo;
	ColorBlendStateInfo mColorBlendStateInfo;
	DynamicStateInfo mDynamicStateInfo;

protected:
	std::vector<VkPipelineShaderStageCreateInfo> mShaderStages;

private:
	VkGraphicsPipelineCreateInfo m_createInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANGRAPHICSPIPELINEINFO_H_ */
