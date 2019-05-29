/*
 * Declaration.h
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKVERTEXLAYOUT_H_
#define SOURCE_RENDER_VK_VKVERTEXLAYOUT_H_

#include "../../Core/GHI/GHIInputLayout.h"
#include "../../Core/GHI/GHIClasses.h"
#include "../../Platform/Vulkan/Pipeline/VulkanGraphicsPipelineInfo.h"

namespace VK
{

class InputLayout
{
public:
	InputLayout(void);
	~InputLayout(void);

public:
	void CreateInputState(const GHI::InputLayout* layout);

public:
	inline const Vulkan::VertexInputStateInfo* GetVertexInputStateInfo(void) const { return &mInputStateInfo; }

public:
	static VkFormat GetElementFormat(GHI::SemanticType type);

protected:
	Vulkan::VertexInputStateInfo mInputStateInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKVERTEXLAYOUT_H_ */
