/*
 * VKVertexInputStateCreateInfo.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTSTATEINFO_H_
#define SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTSTATEINFO_H_

#include <vulkan/vulkan_core.h>
#include <vector>

namespace Vulkan
{

class VertexInputStateInfo
{
public:
	VertexInputStateInfo(void);
	~VertexInputStateInfo(void);

	VkVertexInputBindingDescription* CreateBinding(void);
	VkVertexInputAttributeDescription* CreateAttribute(void);

public:
	VkVertexInputBindingDescription* GetBinding(uint32_t binding);
	VkVertexInputAttributeDescription* GetAttribute(uint32_t binding, uint32_t location);

public:
	VertexInputStateInfo& operator=(const VertexInputStateInfo& other);

public:
	inline const VkPipelineVertexInputStateCreateInfo* CreateInfo(void) const { return &m_createInfo; }

private:
	std::vector<VkVertexInputBindingDescription> m_vertexInputBindings;
	std::vector<VkVertexInputAttributeDescription> m_vertexInputAttributes;

private:
	VkPipelineVertexInputStateCreateInfo m_createInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VULKAN_PIPELINE_VULKANVERTEXINPUTSTATEINFO_H_ */
