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

class GraphicsPipelineInfo: public VkGraphicsPipelineCreateInfo
{
public:
	GraphicsPipelineInfo(void);
	~GraphicsPipelineInfo(void);
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANGRAPHICSPIPELINEINFO_H_ */
