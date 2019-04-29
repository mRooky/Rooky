/*
 * Declaration.h
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKVERTEXLAYOUT_H_
#define SOURCE_RENDER_VK_VKVERTEXLAYOUT_H_

#include <GHIInputLayout.h>
#include "GHIClasses.h"
#include "Pipeline/VulkanGraphicsPipelineInfo.h"

namespace VK
{

class VertexLayout
{
public:
	VertexLayout(void);
	virtual ~VertexLayout(void);

public:
	virtual void CreateInputState(const GHI::InputLayout* layout);

public:
	inline const Vulkan::VertexInputStateInfo* GetVertexInputStateInfo(void) const { return &mInputStateInfo; }

public:
	static VkFormat GetElementFormat(GHI::SemanticType type);

protected:
	Vulkan::VertexInputStateInfo mInputStateInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKVERTEXLAYOUT_H_ */
