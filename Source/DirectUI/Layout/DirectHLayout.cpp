/*
 * DirectHLayout.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#include "DirectHLayout.h"
#include <cassert>

namespace Direct
{

HLayout::HLayout(Widget* parent):
		Layout(parent)
{
}

HLayout::~HLayout(void)
{
}

void HLayout::Draw(Surface* surface)
{
	//update via Container::Rectangle
	for (auto child : mChildren)
	{
		child->Draw(surface);
	}
}

} /* namespace Direct */
