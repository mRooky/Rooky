/*
 * VKInputAssemblyState.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANINPUTASSEMBLYSTATEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANINPUTASSEMBLYSTATEINFO_H_

#include <vulkan/vulkan_core.h>

namespace Vulkan
{

class InputAssemblyStateInfo
{
public:
	InputAssemblyStateInfo(void);
	~InputAssemblyStateInfo(void);

public:
	inline void SetContent(VkPrimitiveTopology topology, bool restart)
	{
		m_createInfo.topology = topology;
		m_createInfo.primitiveRestartEnable = restart ? VK_TRUE : VK_FALSE;
	}

	inline const VkPipelineInputAssemblyStateCreateInfo* CreateInfo(void) const { return &m_createInfo; }

private:
	VkPipelineInputAssemblyStateCreateInfo m_createInfo = {};

};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANINPUTASSEMBLYSTATEINFO_H_ */
