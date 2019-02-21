/*
 * VKColorBlendStateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOLORBLENDSTATEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOLORBLENDSTATEINFO_H_

#include "VulkanColorBlendAttachmentState.h"
#include <vector>

namespace Vulkan
{

class ColorBlendStateInfo
{
public:
	ColorBlendStateInfo(void);
	~ColorBlendStateInfo(void);

public:
	ColorBlendAttachmentState* CreateAttachmentState(void);

public:
	inline size_t GetStateCount(void) const { return m_states.size(); }
	inline const ColorBlendAttachmentState* GetStateData(void) const { return m_states.data(); }
	inline const VkPipelineColorBlendStateCreateInfo* CreateInfo(void) const { return &m_createInfo; }

private:
	std::vector<ColorBlendAttachmentState> m_states;
	VkPipelineColorBlendStateCreateInfo m_createInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOLORBLENDSTATEINFO_H_ */
