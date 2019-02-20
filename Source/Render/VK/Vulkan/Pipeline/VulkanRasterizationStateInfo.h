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

class RasterizationStateInfo: public VkPipelineRasterizationStateCreateInfo
{
public:
	RasterizationStateInfo(void);
	~RasterizationStateInfo(void);

public:
	inline void SetContent(bool clamp, bool discard, VkPolygonMode polygon, VkCullModeFlags cull, VkFrontFace front)
	{
		this->depthClampEnable = clamp ? VK_TRUE : VK_FALSE;
		this->rasterizerDiscardEnable = discard ? VK_TRUE : VK_FALSE;
		this->polygonMode = polygon;
		this->cullMode = cull;
		this->frontFace = front;
	}

	inline void SetDepthBias(bool bias, float constant, float clamp, float slope)
	{
		this->depthBiasEnable = bias ? VK_TRUE : VK_FALSE;
		this->depthBiasConstantFactor = constant;
		this->depthBiasClamp = clamp;
		this->depthBiasSlopeFactor = slope;
	}
	inline void SetLineWidth(float width) { this->lineWidth = width; }
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANRASTERIZATIONSTATEINFO_H_ */
