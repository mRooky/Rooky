/*
 * VKViewportStateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVIEWPORTSTATEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVIEWPORTSTATEINFO_H_

#include <vulkan/vulkan_core.h>
#include <vector>

namespace Vulkan
{

class ViewportStateInfo
{
public:
	ViewportStateInfo(void);
	~ViewportStateInfo(void);

public:
	void AppendScissor(VkRect2D scissor);
	void AppendViewport(VkViewport viewport);

public:
	inline const VkPipelineViewportStateCreateInfo* CreateInfo(void) const { return &m_createInfo; }

private:
	std::vector<VkRect2D> m_scissors;
	std::vector<VkViewport> m_viewports;

private:
	VkPipelineViewportStateCreateInfo m_createInfo = {};

};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVIEWPORTSTATEINFO_H_ */
