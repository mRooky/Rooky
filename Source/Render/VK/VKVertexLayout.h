/*
 * Declaration.h
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKVERTEXLAYOUT_H_
#define SOURCE_RENDER_VK_VKVERTEXLAYOUT_H_

#include "RenderVertexLayout.h"
#include "Pipeline/VulkanGraphicsPipelineInfo.h"

namespace VK
{

class VertexLayout: public Render::VertexLayout
{
public:
	VertexLayout(void);
	virtual ~VertexLayout(void) override;

public:
	void CreateInputState(void);

public:
	inline const Vulkan::VertexInputStateInfo* GetVertexInputStateInfo(void) const { return &mInputStateInfo; }

public:
	static VkFormat GetElementFormat(Render::ElementType type);

protected:
	Vulkan::VertexInputStateInfo mInputStateInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKVERTEXLAYOUT_H_ */
