/*
 * DirectButton.cpp
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#include "DirectButton.h"
#include "DirectPainter.h"
#include "DirectSurface.h"
#include <cassert>

namespace Direct
{

Button::Button(Widget* parent):
		Label(parent)
{
}

Button::~Button(void)
{
}

void Button::Draw(Surface* surface)
{
	assert(mPainter != nullptr);
	auto buffer = surface->GetCommandBuffer();
	mPainter->Binding(buffer);
	assert(false);
}

} /* namespace Direct */
