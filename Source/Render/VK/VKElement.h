/*
 * VKDeclaration.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKELEMENT_H_
#define SOURCE_RENDER_VK_VKELEMENT_H_

#include "RenderElement.h"
#include "VKRender.h"

namespace VK
{
class Context;
class Element: public Render::Element
{
public:
	explicit Element(Context* context);
	virtual ~Element(void) override;

public:
	std::vector<VkVertexInputAttributeDescription> GetInputAttributeDescription(uint32_t binding) const;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKELEMENT_H_ */
