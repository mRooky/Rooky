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

class DynamicStateInfo: public VkPipelineDynamicStateCreateInfo
{
public:
	DynamicStateInfo(void);
	 ~DynamicStateInfo(void);

public:
	 inline void AppendState(VkDynamicState state)
	 {
		 mDynamicStates.push_back(state);
		 this->dynamicStateCount = mDynamicStates.size();
		 this->pDynamicStates = mDynamicStates.data();
	 }

	 inline size_t GetStateCount(void) const { return mDynamicStates.size(); }

private:
	 std::vector<VkDynamicState> mDynamicStates;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANDYNAMICSTATEINFO_H_ */
