/*
 * VKRasterizationState.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKRASTERIZATIONSTATEINFO_H_
#define SOURCE_RENDER_VK_PIPELINE_VKRASTERIZATIONSTATEINFO_H_

#include "RenderTypes.h"
#include <vulkan/vulkan_core.h>

namespace VK
{

class RasterizationStateInfo: public VkPipelineRasterizationStateCreateInfo
{
public:
	RasterizationStateInfo(void);
	~RasterizationStateInfo(void);

public:
	inline void SetContent(bool clamp, bool discard, Render::PolygonMode polygon, Render::CullFaceSide cull, Render::FrontFace front)
	{
		this->depthClampEnable = clamp ? VK_TRUE : VK_FALSE;
		this->rasterizerDiscardEnable = discard ? VK_TRUE : VK_FALSE;
		this->polygonMode = RasterizationStateInfo::Convert(polygon);
		this->cullMode = RasterizationStateInfo::Convert(cull);
		this->frontFace = RasterizationStateInfo::Convert(front);
	}

	inline void SetDepthBias(bool bias, float constant, float clamp, float slope)
	{
		this->depthBiasEnable = bias ? VK_TRUE : VK_FALSE;
		this->depthBiasConstantFactor = constant;
		this->depthBiasClamp = clamp;
		this->depthBiasSlopeFactor = slope;
	}
	inline void SetLineWidth(float width) { this->lineWidth = width; }

public:
	static VkFrontFace Convert(Render::FrontFace front);
	static VkCullModeFlags Convert(Render::CullFaceSide cull);
	static VkPolygonMode Convert(Render::PolygonMode polygon);
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKRASTERIZATIONSTATEINFO_H_ */
