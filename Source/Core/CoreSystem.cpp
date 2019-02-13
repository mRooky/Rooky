/*
 * CoreSystem.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "CoreSystem.h"

#include "RenderContext.h"

#include <cassert>

namespace Core
{

System::System(void)
{
}

System::~System(void)
{
	Render::DestroyContext(mContext);
}

void System::Create(void)
{
	mContext = Render::CreateContext();
	assert(mContext != nullptr);
	mContext->Create();
}

} /* namespace Core */
