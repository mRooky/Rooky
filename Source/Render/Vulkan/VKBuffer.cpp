/*
 * VKBuffer.cpp
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#include "VKBuffer.h"
#include "VKInline.h"
#include "VKFactory.h"
#include "VKDevice.h"
#include "VKPool.h"

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

Buffer::Buffer(Device* device):
		Render::Buffer(device)
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
	Device* vk_device = static_cast<Device*>(mDevice);
	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	mBuffer = Vulkan::Buffer::New(vulkan_device);
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

void Buffer::CopyFrom(const Render::Resource* other)
{
	Device* vk_device = static_cast<Device*>(mDevice);
	Factory* vk_factory = static_cast<Factory*>(mDevice->GetFactory());
	Pool* vk_pool = vk_factory->GetPool();
	Vulkan::CommandPool* command_pool = vk_pool->GetVulkanCommandPool();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	Render::ResourceType type = other->GetType();

	if (type == Render::ResourceType::RESOURCE_TYPE_BUFFER)
	{
		const Buffer* vk_buffer = static_cast<const Buffer*>(other);
		Vulkan::Buffer* vulkan_buffer = vk_buffer->GetVulkanBuffer();

		assert(mSize >= vk_buffer->GetSize());
		VkBufferCopy buffer_copy_range = {};
		buffer_copy_range.size = vk_buffer->GetSize();

		command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
		command_buffer->CopyResource(vulkan_buffer, mBuffer, 1, &buffer_copy_range);
		command_buffer->End();
	}
	else
	{
		assert(false);
	}

	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	Vulkan::Queue* queue = vulkan_device->GetQueue(command_pool->GetFamily(), 0);
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
	flags |= (usage.allocate.Source == TRUE) ? VK_BUFFER_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (usage.allocate.Destination == TRUE) ? VK_BUFFER_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (usage.bufferUsage.IndexBuffer == TRUE) ? VK_BUFFER_USAGE_INDEX_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.VertexBuffer == TRUE) ? VK_BUFFER_USAGE_VERTEX_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.UniformBuffer == TRUE) ? VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.StorageBuffer == TRUE) ? VK_BUFFER_USAGE_STORAGE_BUFFER_BIT : 0;
	flags |= (usage.bufferUsage.IndirectBuffer == TRUE) ? VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT : 0;
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