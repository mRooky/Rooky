/*
 * CoreThread.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include <RenderDevice.h>
#include "CoreThread.h"
#include "CoreSystem.h"

#include "RenderCommandPool.h"
#include "RenderFactory.h"

#include <cassert>

namespace Core
{

Thread::Thread(System* system):
		Interface(system)
{
}

Thread::~Thread(void)
{
	delete mCommandPool;
	mCommandPool = nullptr;
	mCommandLists.clear();
}

void Thread::Create(uint32_t count)
{
	auto device = mSystem->GetDevice();
	auto factory = device->GetFactory();
	mCommandPool = factory->CreateCommandPool();
	mCommandPool->Create();
	for (uint32_t i = 0; i < count; ++i)
	{
		Render::CommandList* command = Allocate(true);
		assert(command != nullptr);
	}
}

Render::CommandList* Thread::Allocate(bool primary)
{
	assert(mCommandPool != nullptr);
	Render::CommandList* command = mCommandPool->Allocate(primary);
	mCommandLists.push_back(command);
	return command;
}

} /* namespace Core */
