/*
 * VKColorBlendStateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOLORBLENDSTATEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOLORBLENDSTATEINFO_H_

#include <vulkan/vulkan_core.h>
#include <vector>

namespace Vulkan
{

class ColorBlendStateInfo
{
public:
	ColorBlendStateInfo(void);
	~ColorBlendStateInfo(void);

public:
	VkPipelineColorBlendAttachmentState* CreateAttachmentState(bool blend);

public:
	void SetColor(size_t index, VkBlendFactor src, VkBlendFactor dst, VkBlendOp operation);
	void SetAlpha(size_t index, VkBlendFactor src, VkBlendFactor dst, VkBlendOp operation);

public:
	inline const VkPipelineColorBlendStateCreateInfo* CreateInfo(void) const { return &m_createInfo; }

public:
	inline size_t GetStateCount(void) const { return m_states.size(); }
	inline const VkPipelineColorBlendAttachmentState* GetStateData(void) const { return m_states.data(); }
	inline const VkPipelineColorBlendAttachmentState& GetState(size_t index) const { return m_states.at(index); }

private:
	VkPipelineColorBlendStateCreateInfo m_createInfo = {};
	std::vector<VkPipelineColorBlendAttachmentState> m_states;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANCOLORBLENDSTATEINFO_H_ */
