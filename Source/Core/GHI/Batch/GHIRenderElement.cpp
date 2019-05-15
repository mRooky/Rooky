/*
 * GHIRenderElement.cpp
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#include "GHIRenderElement.h"
#include "GHICommandList.h"
#include <cassert>

namespace GHI
{

RenderElement::RenderElement(RenderItem* parent, Draw* draw):
		mDraw(draw), mParent(parent)
{
	assert(mDraw != nullptr);
	assert(mParent != nullptr);
}

RenderElement::~RenderElement(void)
{
}

void RenderElement::Render(CommandList* command)
{
	command->Draw(mDraw);
}

} /* namespace GHI */
