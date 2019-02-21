/*
 * VKDynamicStateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANDYNAMICSTATEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANDYNAMICSTATEINFO_H_

#include <vulkan/vulkan_core.h>
#include <vector>

namespace Vulkan
{

class DynamicStateInfo
{
public:
	DynamicStateInfo(void);
	~DynamicStateInfo(void);

public:
	inline void AppendState(VkDynamicState state)
	{
		m_dynamicStates.push_back(state);
		m_createInfo.dynamicStateCount = m_dynamicStates.size();
		m_createInfo.pDynamicStates = m_dynamicStates.data();
	}

	inline size_t GetStateCount(void) const	{ return m_dynamicStates.size(); }
	inline const VkPipelineDynamicStateCreateInfo* CreateInfo(void) const { return &m_createInfo; }

private:
	std::vector<VkDynamicState> m_dynamicStates;
	VkPipelineDynamicStateCreateInfo m_createInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANDYNAMICSTATEINFO_H_ */
