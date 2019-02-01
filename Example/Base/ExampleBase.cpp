/*
 * ExampleBase.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "ExampleBase.h"
#include "RenderContext.h"
#include "CoreViewport.h"
#include <cassert>

namespace Example
{

Base::Base(const char* title)
{
	assert(title != nullptr);
	mContext = Render::CreateContext();
	assert(mContext != nullptr);
	mContext->Initialize(title);
}

Base::~Base(void)
{
	Render::DestroyContext(mContext);
}

int32_t Base::ShowModal(void)
{
	assert(mContext != nullptr);
	Platform::Window* window = mContext->GetWindow();
	assert(window != nullptr);
	bool done = false;
	while (!done)
	{
		done = window->HandleEvent();
	}
	return 0;
}

} /* namespace Example */
