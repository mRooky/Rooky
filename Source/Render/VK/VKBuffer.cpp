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
#include "VulkanCommandPool.h"
#include "VulkanCommandBuffer.h"
#include "VulkanDevice.h"
#include "VulkanQueue.h"

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
	assert(mMemory == nullptr);
	mSize = size;
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetDeviceVK();
	mBuffer = Vulkan::Buffer::New(device);
	mBuffer->Create(size, usage);
}

void Buffer::AllocateMemory(uint32_t properties)
{
	Context* context = static_cast<Context*>(mContext);
	Memory* vk_memory = new Memory(context);
	vk_memory->Allocate(mBuffer, properties);
	mBuffer->BindMemory(vk_memory->GetMemoryVK(), 0);
	mMemory = vk_memory;
}

void Buffer::Copy(const Render::Buffer& other)
{
	Context* context = static_cast<Context*>(mContext);
	Vulkan::CommandPool* command_pool = context->GetCommandPoolVK();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	assert(mSize >= other.GetSize());
	VkBufferCopy buffer_copy_range = {};
	buffer_copy_range.size = other.GetSize();

	const Buffer& buffer = static_cast<const Buffer&>(other);
	command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
	command_buffer->CopyResource(buffer.GetBufferVK(), mBuffer, 1, &buffer_copy_range);
	command_buffer->End();

	Vulkan::Device* device = context->GetDeviceVK();
	Vulkan::Queue* queue = device->GetQueue(command_pool->GetFamily(), 0);
	queue->FlushCommandBuffer(command_buffer);
}

VkDescriptorBufferInfo Buffer::GetDescriptorInfo(void) const
{
	assert(mBuffer != nullptr);
	assert(mMemory != nullptr);
	VkDescriptorBufferInfo descriptor_info = {};
	descriptor_info.buffer = mBuffer->GetHandle();
	descriptor_info.offset = 0;
	descriptor_info.range = mSize;
	return descriptor_info;
}

} /* namespace VK */
