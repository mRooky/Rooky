/*
 * VKBuffer.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKBuffer.h"
#include "VKContext.h"
#include "VKInline.h"
#include "VKFactory.h"

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

void Buffer::Create(size_t size, const Render::ResourceUsage& usage)
{
	mSize = size;
	mUsage = usage;
	CreateBuffer();
	AllocateMemory();
}

void Buffer::CreateBuffer(void)
{
	assert(mBuffer == nullptr);
	Context* context = StaticCast(mContext);
	Vulkan::Device* device = context->GetVulkanDevice();
	mBuffer = Vulkan::Buffer::New(device);
	mBuffer->Create(mSize, Buffer::ConvertUsageFlag(mUsage));
}

void Buffer::AllocateMemory(void)
{
	assert(mBuffer != nullptr);
	auto flags = GetMemoryPropertyFlags(mUsage.heap);
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

void Buffer::Download(void* dst)
{

}

void Buffer::Upload(const void* src)
{

}

void Buffer::CopyFrom(const Render::Buffer* other)
{
	Context* context = StaticCast(mContext);
	Factory* factory = StaticCast(mContext->GetFactory());
	Vulkan::CommandPool* command_pool = factory->GetVulkanCommandPool();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	assert(mSize >= other->GetSize());
	VkBufferCopy buffer_copy_range = {};
	buffer_copy_range.size = other->GetSize();

	const Buffer* buffer = StaticCast(other);
	Vulkan::Buffer* vk_buffer = buffer->GetVulkanBuffer();

	command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
	command_buffer->CopyResource(vk_buffer, mBuffer, 1, &buffer_copy_range);
	command_buffer->End();

	Vulkan::Device* device = context->GetVulkanDevice();
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

VkBufferUsageFlags Buffer::ConvertUsageFlag(Render::ResourceUsage usage)
{
	VkBufferUsageFlags flags = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
	if (usage.heap.Transform == 1)
	{
		flags |= VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
	}
	if (usage.binding.IndexBuffer == 1)
	{
		flags |= VK_BUFFER_USAGE_INDEX_BUFFER_BIT;
	}
	if (usage.binding.VertexBuffer == 1)
	{
		flags |= VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
	}
	if (usage.binding.UniformBuffer == 1)
	{
		flags |= VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT;
	}
	if (usage.binding.StorageBuffer == 1)
	{
		flags |= VK_BUFFER_USAGE_STORAGE_BUFFER_BIT;
	}
	if (usage.binding.IndirectBuffer == 1)
	{
		flags |= VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT;
	}
	return flags;
}

} /* namespace VK */
