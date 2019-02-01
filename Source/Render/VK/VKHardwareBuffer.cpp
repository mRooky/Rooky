/*
 * VKBuffer.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKHardwareBuffer.h"
#include "VKContext.h"
#include "VKMemory.h"

#include "VulkanBuffer.h"
#include "VulkanInline.h"
#include "VulkanCommandPool.h"
#include "VulkanCommandBuffer.h"
#include "VulkanDevice.h"
#include "VulkanQueue.h"

#include <cassert>

namespace VK
{

HardwareBuffer::HardwareBuffer(Context* context):
		Render::HardwareBuffer(context)
{
}

HardwareBuffer::~HardwareBuffer(void)
{
	Vulkan::Release(mBuffer);
}

void HardwareBuffer::Initialize(size_t size, uint32_t usage)
{
	assert(mBuffer == nullptr);
	assert(mBuffer == nullptr);
	mSize = size;
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetDeviceVK();
	mBuffer = Vulkan::Buffer::New(device);
	mBuffer->Create(size, usage);
}

void HardwareBuffer::BindMemory(Render::Memory* memory, size_t offset)
{
	assert(memory != nullptr);
	assert(mMemory == nullptr);
	mMemory = memory;
	mOffset = offset;
	Memory* vk_memory = static_cast<Memory*>(mMemory);
	mBuffer->BindMemory(vk_memory->GetMemoryVK(), offset);
}

void HardwareBuffer::CopyFrom(const Render::HardwareBuffer& other)
{
	Context* context = static_cast<Context*>(mContext);
	Vulkan::CommandPool* command_pool = context->GetCommandPoolVK();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	assert(mSize >= other.GetSize());
	VkBufferCopy buffer_copy_range = {};
	buffer_copy_range.size = other.GetSize();

	const HardwareBuffer& buffer = static_cast<const HardwareBuffer&>(other);
	command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
	command_buffer->CopyResource(buffer.GetBufferVK(), mBuffer, 1, &buffer_copy_range);
	command_buffer->End();

	Vulkan::Device* device = context->GetDeviceVK();
	Vulkan::Queue* queue = device->GetQueue(command_pool->GetFamily(), 0);
	queue->FlushCommandBuffer(command_buffer);
}

VkDescriptorBufferInfo HardwareBuffer::GetDescriptorInfo(void) const
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
