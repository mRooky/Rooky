/*
 * VKDeclaration.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKDECLARATION_H_
#define SOURCE_RENDER_VK_VKDECLARATION_H_

#include "RenderDeclaration.h"
#include "VKRender.h"

namespace VK
{
class Context;
class Declaration: public Render::Declaration
{
public:
	explicit Declaration(Context* context);
	virtual ~Declaration(void) override;

public:
	std::vector<VkVertexInputAttributeDescription> GetInputAttributeDescription(uint32_t binding) const;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKDECLARATION_H_ */
