/*
 * Declaration.h
 *
 *  Created on: Mar 7, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKDECLARATION_H_
#define SOURCE_RENDER_VK_VKDECLARATION_H_

#include "RenderDeclaration.h"
#include "Pipeline/VulkanGraphicsPipelineInfo.h"

namespace VK
{

class Declaration: public Render::Declaration
{
public:
	Declaration(void);
	virtual ~Declaration(void) override;

public:
	virtual void Create(void) override;

protected:
	Vulkan::VertexInputStateInfo mVertexInputStateInfo = {};
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKDECLARATION_H_ */
