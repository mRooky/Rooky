/*
 * Label.cpp
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#include "DirectLabel.h"
#include "DirectPainter.h"
#include "DirectSurface.h"
#include <cassert>

namespace Direct
{

Label::Label(Widget* parent):
		Control(parent)
{
}

Label::~Label(void)
{
	mForeGround = nullptr;
	mForeMask = nullptr;
	mBackGround = nullptr;
	mCaption = "";
}

void Label::Draw(Surface* surface)
{
	assert(mPainter != nullptr);
	Vulkan::CommandBuffer* buffer = surface->GetCommandBuffer();
	mPainter->Binding(buffer);
	assert(false);
}

} /* namespace Direct */
