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
	Context* context = static_cast<Context*>(mContext);
	Vulkan::Device* device = context->GetVulkanDevice();
	mBuffer = Vulkan::Buffer::New(device);
	mBuffer->Create(mSize, Buffer::ConvertUsageFlag(mUsage));
}

void Buffer::AllocateMemory(void)
{
	assert(mBuffer != nullptr);
	auto flags = GetMemoryPropertyFlags(mUsage.allocate);
	Vulkan::Device* device = mBuffer->GetDevice();
	const auto& requires = mBuffer->GetMemoryRequirements();
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
	Context* context = static_cast<Context*>(mContext);
	Factory* factory = static_cast<Factory*>(mContext->GetFactory());
	Vulkan::CommandPool* command_pool = factory->GetVulkanCommandPool();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	assert(mSize >= other->GetSize());
	VkBufferCopy buffer_copy_range = {};
	buffer_copy_range.size = other->GetSize();

	const Buffer* buffer = static_cast<const Buffer*>(other);
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
	assert(usage.type == Render::ResourceType::RESOURCE_TYPE_BUFFER);
	VkBufferUsageFlags flags = 0;
	flags |= (usage.allocate.Source == 1) ? VK_BUFFER_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (usage.allocate.Destination == 1) ? VK_BUFFER_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (usage.bufferUsage.IndexBuffer == 1) ? VK_BUFFER_USAGE_INDEX_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.VertexBuffer == 1) ? VK_BUFFER_USAGE_VERTEX_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.UniformBuffer == 1) ? VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.StorageBuffer == 1) ? VK_BUFFER_USAGE_STORAGE_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.IndirectBuffer == 1) ? VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT : 0;
	return flags;
}

VkDescriptorType Buffer::GetDescriptorType(const Render::BufferUsage& usage)
{
	VkDescriptorType descriptor_type =
	(usage.UniformBuffer == 1) ? VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER :
	(usage.StorageBuffer == 1) ? VK_DESCRIPTOR_TYPE_STORAGE_BUFFER :
	(usage.UniformTexel == 1) ? VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER :
	(usage.StorageTexel == 1) ? VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER: VK_DESCRIPTOR_TYPE_MAX_ENUM;
	assert(descriptor_type != VK_DESCRIPTOR_TYPE_MAX_ENUM);
	return descriptor_type;
}

} /* namespace VK */
