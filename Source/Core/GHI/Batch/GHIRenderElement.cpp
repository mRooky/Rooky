/*
 * GHIRenderElement.cpp
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#include "GHIRenderElement.h"

namespace GHI
{

RenderElement::RenderElement(RenderItem* parent, Draw* draw):
		mDraw(draw), mParent(parent)
{
}

RenderElement::~RenderElement(void)
{
}

} /* namespace GHI */
