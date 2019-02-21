/*
 * VKMultisampleStateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANMULTISAMPLESTATEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANMULTISAMPLESTATEINFO_H_

#include <vulkan/vulkan_core.h>

namespace Vulkan
{

class MultisampleStateInfo
{
public:
	MultisampleStateInfo(void);
	~MultisampleStateInfo(void);

public:
	inline void SetContent(uint32_t count)
	{
		m_createInfo.rasterizationSamples = static_cast<VkSampleCountFlagBits>(count);
	}

	inline const VkPipelineMultisampleStateCreateInfo* CreateInfo(void) const { return &m_createInfo; }

private:
	VkPipelineMultisampleStateCreateInfo m_createInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANMULTISAMPLESTATEINFO_H_ */
