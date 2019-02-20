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

class ViewportStateInfo: public VkPipelineViewportStateCreateInfo
{
public:
	ViewportStateInfo(void);
	~ViewportStateInfo(void);

public:
	void AppendScissor(VkRect2D scissor);
	void AppendViewport(VkViewport viewport);

private:
	std::vector<VkRect2D> mScissors;
	std::vector<VkViewport> mViewports;

};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVIEWPORTSTATEINFO_H_ */
