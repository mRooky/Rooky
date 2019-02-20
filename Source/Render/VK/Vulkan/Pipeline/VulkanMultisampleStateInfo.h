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

class MultisampleStateInfo: public VkPipelineMultisampleStateCreateInfo
{
public:
	MultisampleStateInfo(void);
	~MultisampleStateInfo(void);

public:
	inline void SetContent(uint32_t count)
	{
		this->rasterizationSamples = static_cast<VkSampleCountFlagBits>(count);
	}
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANMULTISAMPLESTATEINFO_H_ */
