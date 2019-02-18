/*
 * VKDepthStencilStateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKDEPTHSTENCILSTATEINFO_H_
#define SOURCE_RENDER_VK_PIPELINE_VKDEPTHSTENCILSTATEINFO_H_

#include "RenderTypes.h"
#include <vulkan/vulkan_core.h>

namespace VK
{

class DepthStencilStateInfo: public VkPipelineDepthStencilStateCreateInfo
{
public:
	DepthStencilStateInfo(void);
	~DepthStencilStateInfo(void);

public:
	inline void SetDepth(bool test, bool write, Render::CompareOperation operation, bool bound)
	{
		this->depthTestEnable = test ? VK_TRUE : VK_FALSE;
		this->depthWriteEnable = write ? VK_TRUE : VK_FALSE;
		this->depthCompareOp = DepthStencilStateInfo::Convert(operation);
		this->depthBoundsTestEnable = bound ? VK_TRUE : VK_FALSE;
	}

public:
	static VkCompareOp Convert(Render::CompareOperation operation);
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKDEPTHSTENCILSTATEINFO_H_ */
