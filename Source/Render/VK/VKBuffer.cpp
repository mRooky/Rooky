/*
 * VKBuffer.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKBuffer.h"
#include "VKContext.h"

#include "VulkanBuffer.h"
#include "VulkanInline.h"
#include "VulkanCommandPool.h"
#include "VulkanCommandBuffer.h"
#include "VulkanDevice.h"
#include "VulkanQueue.h"
#include "VulkanDeviceMemory.h"

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

void Buffer::Create(size_t size, uint32_t usage)
{
	assert(mBuffer == nullptr);
	mSize = size;
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetDeviceVK();
	mBuffer = Vulkan::Buffer::New(device);
	mBuffer->Create(size, usage);
}

void Buffer::Allocate(uint32_t properties)
{
	assert(mBuffer != nullptr);
	Vulkan::Device* device = mBuffer->GetDevice();
	mMemory = Vulkan::DeviceMemory::New(device);
	mMemory->Allocate(mBuffer, properties);
	mBuffer->BindMemory(mMemory, 0);
}

void Buffer::CopyFrom(const Render::Buffer* other)
{
	Context* context = static_cast<Context*>(mContext);
	Vulkan::CommandPool* command_pool = context->GetCommandPoolVK();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	assert(mSize >= other->GetSize());
	VkBufferCopy buffer_copy_range = {};
	buffer_copy_range.size = other->GetSize();

	const Buffer* buffer = static_cast<const Buffer*>(other);
	Vulkan::Buffer* vk_buffer = buffer->GetBufferVK();

	command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
	command_buffer->CopyResource(vk_buffer, mBuffer, 1, &buffer_copy_range);
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
