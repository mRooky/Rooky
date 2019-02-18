/*
 * VKColorBlendStateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKCOLORBLENDSTATEINFO_H_
#define SOURCE_RENDER_VK_PIPELINE_VKCOLORBLENDSTATEINFO_H_

#include "VKColorBlendAttachmentState.h"
#include <vector>

namespace VK
{

class ColorBlendStateInfo: public VkPipelineColorBlendStateCreateInfo
{
public:
	ColorBlendStateInfo(void);
	~ColorBlendStateInfo(void);

public:
	ColorBlendAttachmentState* CreateState(void);

public:
	inline size_t GetStateCount(void) const { return mStates.size(); }
	inline const ColorBlendAttachmentState* GetStateData(void) const { return mStates.data(); }

private:
	std::vector<ColorBlendAttachmentState> mStates;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKCOLORBLENDSTATEINFO_H_ */
