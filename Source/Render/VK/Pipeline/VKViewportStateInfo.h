/*
 * VKViewportStateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKVIEWPORTSTATEINFO_H_
#define SOURCE_RENDER_VK_PIPELINE_VKVIEWPORTSTATEINFO_H_

#include "RenderMath.h"
#include <vulkan/vulkan_core.h>
#include <vector>

namespace VK
{

class ViewportStateInfo: public VkPipelineViewportStateCreateInfo
{
public:
	ViewportStateInfo(void);
	~ViewportStateInfo(void);

public:
	void SetScissor(Render::Rect2D scissor);
	void SetViewport(Render::Viewport viewport);

private:
	std::vector<VkRect2D> mScissors;
	std::vector<VkViewport> mViewports;

};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKVIEWPORTSTATEINFO_H_ */
