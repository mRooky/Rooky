/*
 * GHIRenderItem.cpp
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#include "GHIRenderItem.h"

namespace GHI
{

RenderItem::RenderItem(void)
{
}

RenderItem::~RenderItem(void)
{
}

RenderElement* RenderItem::CreateElement(Draw* draw)
{
	RenderElement element(this, draw);
	mRenderElements.push_back(element);
	return &mRenderElements.back();
}

} /* namespace GHI */
