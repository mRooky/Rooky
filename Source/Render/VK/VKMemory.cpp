/*
 * VKMemory.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKMemory.h"
#include "VKContext.h"

#include "VulkanDeviceMemory.h"
#include "VulkanInline.h"

#include <cassert>

namespace VK
{

Memory::Memory(Context* context):
		Render::Memory(context)
{
}

Memory::~Memory(void)
{
	Vulkan::Release(mMemory);
}

void Memory::Allocate(Vulkan::Resource* resource, uint32_t properties)
{
	assert(mMemory == nullptr);
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetDeviceVK();
	mMemory = Vulkan::DeviceMemory::New(device);
	mMemory->Allocate(resource, properties);
}

void* Memory::Mapped(size_t offset, size_t range)
{
	assert(mMemory != nullptr);
	void* ptr = mMemory->Map(offset, range);
	assert(ptr != nullptr);
	return ptr;
}

void Memory::UnMap(size_t offset, size_t range)
{
	assert(mMemory != nullptr);
	mMemory->Flush(offset, range);
	mMemory->Unmap();
}

} /* namespace VK */
