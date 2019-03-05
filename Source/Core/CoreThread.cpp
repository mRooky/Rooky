/*
 * CoreThread.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "CoreThread.h"
#include "CoreSystem.h"

#include "RenderCommandPool.h"
#include "RenderContext.h"
#include "RenderFactory.h"

#include <cassert>

namespace Core
{

Thread::Thread(System* system):
		Object(system)
{
}

Thread::~Thread(void)
{
	delete mCommandPool;
	mCommandPool = nullptr;
	mCommandLists.clear();
}

void Thread::Create(void)
{
	auto context = mSystem->GetContext();
	mCommandPool = context->GetFactory()->CreateCommandPool();
	mCommandPool->Create();
}

Render::CommandList* Thread::Allocate(bool primary)
{
	assert(mCommandPool != nullptr);
	Render::CommandList* command = mCommandPool->Allocate(primary);
	mCommandLists.push_back(command);
	return command;
}

} /* namespace Core */
