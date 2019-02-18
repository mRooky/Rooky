/*
 * VKInputAssemblyState.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_PIPELINE_VKINPUTASSEMBLYSTATEINFO_H_
#define SOURCE_RENDER_VK_PIPELINE_VKINPUTASSEMBLYSTATEINFO_H_

#include "RenderTypes.h"

#include <vulkan/vulkan_core.h>

namespace VK
{

class InputAssemblyStateInfo: public VkPipelineInputAssemblyStateCreateInfo
{
public:
	InputAssemblyStateInfo(void);
	~InputAssemblyStateInfo(void);

public:
	inline void SetContent(Render::PrimitiveTopology topology, bool restart)
	{
		this->primitiveRestartEnable = restart ? VK_TRUE : VK_FALSE;
		this->topology = InputAssemblyStateInfo::Convert(topology);
	}

public:
	static VkPrimitiveTopology Convert(Render::PrimitiveTopology topology);
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_PIPELINE_VKINPUTASSEMBLYSTATEINFO_H_ */
