/*
 * CoreSystem.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "CoreSystem.h"
#include "CoreBufferManager.h"

#include "RenderContext.h"

#include <cassert>

namespace Core
{

System::System(void)
{
}

System::~System(void)
{
	delete mBufferManager;
	mBufferManager = nullptr;
	Render::DestroyContext(mContext);
}

void System::Create(void)
{
	mContext = Render::CreateContext();
	assert(mContext != nullptr);
	mContext->Create();
	mBufferManager = new BufferManager(this);
}

} /* namespace Core */
