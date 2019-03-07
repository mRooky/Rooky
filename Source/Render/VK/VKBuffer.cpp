/*
 * VKBuffer.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKBuffer.h"
#include "VKContext.h"
#include "VKInline.h"

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
	Vulkan::Release(mMemory);
}

void Buffer::Create(size_t size, uint32_t usage)
{
	mSize = size;
	mUsage.BufferUsageFlags = usage;
	assert(mBuffer == nullptr);
	Context* context = StaticCast(mContext);
	Vulkan::Device* device = context->GetDeviceVK();
	mBuffer = Vulkan::Buffer::New(device);
	mBuffer->Create(mSize, Buffer::ConvertUsageFlag(mUsage));
}

void Buffer::Allocate(Render::HeapAccess access)
{
	mAccess = access;
	assert(mBuffer != nullptr);
	auto flags = GetMemoryPropertyFlags(mAccess);
	Vulkan::Device* device = mBuffer->GetDevice();
	const VkMemoryRequirements& requires = mBuffer->GetMemoryRequirements();
	mHeapSize = requires.size;
	mMemory = Vulkan::DeviceMemory::New(device);
	mMemory->Allocate(requires, flags);
	mBuffer->BindMemory(mMemory, 0);
}

void* Buffer::Map(size_t offset, size_t size)
{
	assert(mMemory != nullptr);
	return mMemory->Map(offset, size);
}

void Buffer::Unmap(size_t offset, size_t size)
{
	assert(mMemory != nullptr);
	mMemory->Unmap();
	mMemory->Flush(offset, size);
}

void Buffer::CopyFrom(const Render::Buffer* other)
{
	Context* context = StaticCast(mContext);
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

VkBufferUsageFlags Buffer::ConvertUsageFlag(Render::BufferUsage usage)
{
	VkBufferUsageFlags flags = 0;
	if (usage.BufferUsageCommon == 1)
	{
		flags |= VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
		flags |= VK_BUFFER_USAGE_TRANSFER_DST_BIT;
	}
	if (usage.BufferUsageIndex == 1)
	{
		flags |= VK_BUFFER_USAGE_INDEX_BUFFER_BIT;
	}
	if (usage.BufferUsageVertex == 1)
	{
		flags |= VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
	}
	if (usage.BufferUsageUniform == 1)
	{
		flags |= VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;
	}
	if (usage.BufferUsageStorage == 1)
	{
		flags |= VK_BUFFER_USAGE_STORAGE_BUFFER_BIT;
	}
	if (usage.BufferUsageIndirect == 1)
	{
		flags |= VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT;
	}
	if (usage.BufferUsageUniformTexel == 1)
	{
		flags |= VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT;
	}
	if (usage.BufferUsageStorageTexel == 1)
	{
		flags |= VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT;
	}

	return flags;
}

} /* namespace VK */
