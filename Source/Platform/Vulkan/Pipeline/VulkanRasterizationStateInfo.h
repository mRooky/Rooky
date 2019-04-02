/*
 * VKRasterizationState.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANRASTERIZATIONSTATEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANRASTERIZATIONSTATEINFO_H_

#include <vulkan/vulkan_core.h>

namespace Vulkan
{

class RasterizationStateInfo
{
public:
	RasterizationStateInfo(void);
	~RasterizationStateInfo(void);

public:
	inline void SetLineWidth(float width) { m_createInfo.lineWidth = width; }
	inline const VkPipelineRasterizationStateCreateInfo* CreateInfo(void) const { return &m_createInfo; }

public:
	inline void SetContent(bool clamp, bool discard, VkPolygonMode polygon, VkCullModeFlags cull, VkFrontFace front)
	{
		m_createInfo.depthClampEnable = clamp ? VK_TRUE : VK_FALSE;
		m_createInfo.rasterizerDiscardEnable = discard ? VK_TRUE : VK_FALSE;
		m_createInfo.polygonMode = polygon;
		m_createInfo.cullMode = cull;
		m_createInfo.frontFace = front;
	}

	inline void SetDepthBias(bool bias, float constant, float clamp, float slope)
	{
		m_createInfo.depthBiasEnable = bias ? VK_TRUE : VK_FALSE;
		m_createInfo.depthBiasConstantFactor = constant;
		m_createInfo.depthBiasClamp = clamp;
		m_createInfo.depthBiasSlopeFactor = slope;
	}

private:
	VkPipelineRasterizationStateCreateInfo m_createInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANRASTERIZATIONSTATEINFO_H_ */
