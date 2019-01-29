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

void Memory::Initialize(size_t size, uint32_t index, uint32_t property)
{
	assert(mMemory == nullptr);
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetDeviceVK();
	mMemory = Vulkan::DeviceMemory::New(device);
	mMemory->Allocate(size, index, property);
}

} /* namespace VK */
