/*
 * VKDepthStencilStateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANDEPTHSTENCILSTATEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANDEPTHSTENCILSTATEINFO_H_

#include <vulkan/vulkan_core.h>

namespace Vulkan
{

class DepthStencilStateInfo: public VkPipelineDepthStencilStateCreateInfo
{
public:
	DepthStencilStateInfo(void);
	~DepthStencilStateInfo(void);

public:
	inline void SetDepth(bool test, bool write, VkCompareOp operation, bool bound)
	{
		this->depthTestEnable = test ? VK_TRUE : VK_FALSE;
		this->depthWriteEnable = write ? VK_TRUE : VK_FALSE;
		this->depthCompareOp = operation;
		this->depthBoundsTestEnable = bound ? VK_TRUE : VK_FALSE;
	}

};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANDEPTHSTENCILSTATEINFO_H_ */
