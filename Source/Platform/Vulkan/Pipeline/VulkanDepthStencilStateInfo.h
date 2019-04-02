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

class DepthStencilStateInfo
{
public:
	DepthStencilStateInfo(void);
	~DepthStencilStateInfo(void);

public:
	inline const VkPipelineDepthStencilStateCreateInfo* CreateInfo(void) const { return &m_createInfo; }

public:
	inline void SetDepth(bool test, bool write, VkCompareOp operation, bool bound)
	{
		m_createInfo.depthTestEnable = test ? VK_TRUE : VK_FALSE;
		m_createInfo.depthWriteEnable = write ? VK_TRUE : VK_FALSE;
		m_createInfo.depthCompareOp = operation;
		m_createInfo.depthBoundsTestEnable = bound ? VK_TRUE : VK_FALSE;
	}

	inline void SetStencil(bool test);

private:
	VkPipelineDepthStencilStateCreateInfo m_createInfo = {};

};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANDEPTHSTENCILSTATEINFO_H_ */
