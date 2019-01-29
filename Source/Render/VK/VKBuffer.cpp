/*
 * VKBuffer.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKBuffer.h"
#include "VKContext.h"
#include "VKMemory.h"

#include "VulkanBuffer.h"
#include "VulkanInline.h"

#include <cassert>

namespace VK
{

Buffer::Buffer(Context* context):
		Render::Buffer(context)
{
}

Buffer::~Buffer(void)
{
	Vulkan::Release(mBuffer);
}

void Buffer::Initialize(size_t size, uint32_t usage)
{
	assert(mBuffer == nullptr);
	assert(mBuffer == nullptr);
	mSize = size;
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetDeviceVK();
	mBuffer = Vulkan::Buffer::New(device);
	mBuffer->Create(size, usage);
}

void Buffer::BindMemory(Render::Memory* memory, size_t offset)
{
	assert(memory != nullptr);
	assert(mMemory == nullptr);
	mMemory = memory;
	mOffset = offset;
	Memory* vk_memory = static_cast<Memory*>(mMemory);
	mBuffer->BindMemory(vk_memory->GetMemoryVK(), offset);
}

VkDescriptorBufferInfo Buffer::GetDescriptorInfo(void) const
{
	assert(mBuffer != nullptr);
	assert(mMemory != nullptr);
	VkDescriptorBufferInfo descriptor_info = {};
	descriptor_info.buffer = mBuffer->GetHandle();
	descriptor_info.offset = mOffset;
	descriptor_info.range = mSize;
	return descriptor_info;
}

} /* namespace VK */
