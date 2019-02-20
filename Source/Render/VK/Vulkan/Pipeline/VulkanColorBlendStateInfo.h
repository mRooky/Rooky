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

class ColorBlendStateInfo: public VkPipelineColorBlendStateCreateInfo
{
public:
	ColorBlendStateInfo(void);
	~ColorBlendStateInfo(void);

public:
	ColorBlendAttachmentState* CreateAttachmentState(void);

public:
	inline size_t GetStateCount(void) const { return mStates.size(); }
	inline const ColorBlendAttachmentState* GetStateData(void) const { return mStates.data(); }

private:
	std::vector<ColorBlendAttachmentState> mStates;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOLORBLENDSTATEINFO_H_ */
