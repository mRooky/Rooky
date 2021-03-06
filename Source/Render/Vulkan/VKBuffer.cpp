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

#include "../../Platform/Vulkan/VulkanBuffer.h"
#include "../../Platform/Vulkan/VulkanInline.h"
#include "../../Platform/Vulkan/VulkanCommandPool.h"
#include "../../Platform/Vulkan/VulkanCommandBuffer.h"
#include "../../Platform/Vulkan/VulkanDevice.h"
#include "../../Platform/Vulkan/VulkanQueue.h"
#include "../../Platform/Vulkan/VulkanDeviceMemory.h"

#include <cassert>
#include <cstring>
#include <iostream>

namespace VK
{

Buffer::Buffer(Device* device):
		GHI::Buffer(device)
{
}

Buffer::~Buffer(void)
{
	Vulkan::Release(mBuffer);
	Vulkan::Release(mMemory);
}

void Buffer::Create(size_t size, const GHI::ResourceUsage& usage)
{
	mSize = size;
	mUsage = usage;
	CreateVulkanBuffer();
	AllocateVulkanMemory();
}

void Buffer::CreateVulkanBuffer(void)
{
	assert(mBuffer == nullptr);
	Device* vk_device = static_cast<Device*>(mDevice);
	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	auto flags = ConvertUsageFlag();
	mBuffer = Vulkan::Buffer::New(vulkan_device);
	mBuffer->Create(mSize, flags);
}

void Buffer::AllocateVulkanMemory(void)
{
	assert(mBuffer != nullptr);
	auto flags = GetMemoryPropertyFlags(mUsage);
	Vulkan::Device* device = mBuffer->GetDevice();
	const auto& requires = mBuffer->GetMemoryRequirements();
	mAlignSize = requires.size;
	mMemory = Vulkan::DeviceMemory::New(device);
	mMemory->Allocate(requires, flags);
	mBuffer->BindMemory(mMemory, 0);
}

void* Buffer::Map(size_t offset, size_t size)
{
	std::cout << "Memory Ptr " << mMemory << std::endl;
	assert(mMemory != nullptr);
	if (mUsage.memoryType.CPUAccessable())
	{
		return mMemory->Map(offset, size);
	}
	return nullptr;
}

void Buffer::Unmap(size_t offset, size_t size)
{
	assert(mMemory != nullptr);
	mMemory->Unmap();
	mMemory->Flush(offset, size);
}

void Buffer::Download(void* dst, size_t offset, size_t size)
{
	std::cout << "[VK] Download Buffer Data" << std::endl;
	assert(mMemory != nullptr);
	assert(size != 0 && dst != nullptr);
	GHI::Factory* factory = mDevice->GetFactory();
	Factory* vk_factory = static_cast<Factory*>(factory);
	Pool* vk_pool = vk_factory->GetPool();
	Vulkan::CommandPool* command_pool = vk_pool->GetVulkanCommandPool();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	GHI::ResourceUsage usage = {};
	usage.memoryType.cpuAccess = TRUE;
	usage.memoryType.read = TRUE;
	usage.memoryType.write = TRUE;

	Buffer* stage_buffer = vk_pool->GetStageBuffer(size);
	auto vulkan_buffer = stage_buffer->GetVulkanBuffer();

	VkBufferCopy copy_region = {};
	copy_region.srcOffset = offset;
	copy_region.dstOffset = 0;
	copy_region.size = size;

	command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
	command_buffer->CopyResource(mBuffer, vulkan_buffer, 1, &copy_region);
	command_buffer->End();

	auto vk_device = static_cast<Device*>(mDevice);
	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	uint32_t queue_family = command_pool->GetFamily();
	Vulkan::Queue* queue = vulkan_device->GetQueue(queue_family, 0);
	queue->FlushCommandBuffer(command_buffer);

	assert(stage_buffer->GetUsage().GetMemoryType().CPUAccessable());
	stage_buffer->Read(dst, 0, size);
}

void Buffer::Upload(const void* src, size_t offset, size_t size)
{
	std::cout << "[VK] Upload Buffer Data" << std::endl;
	assert(mMemory != nullptr);
	assert(size != 0 && src != nullptr);
	GHI::Factory* factory = mDevice->GetFactory();
	Factory* vk_factory = static_cast<Factory*>(factory);
	Pool* vk_pool = vk_factory->GetPool();
	Vulkan::CommandPool* command_pool = vk_pool->GetVulkanCommandPool();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	Buffer* stage_buffer = vk_pool->GetStageBuffer(size);
	assert(stage_buffer->GetUsage().GetMemoryType().CPUAccessable());
	stage_buffer->Write(src, 0, size);

	VkBufferCopy copy_region = {};
	copy_region.srcOffset = 0;
	copy_region.dstOffset = offset;
	copy_region.size = size;
	auto vulkan_buffer = stage_buffer->GetVulkanBuffer();

	command_buffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
	command_buffer->CopyResource(vulkan_buffer, mBuffer, 1, &copy_region);
	command_buffer->End();

	auto vk_device = static_cast<Device*>(mDevice);
	Vulkan::Device* vulkan_device = vk_device->GetVulkanDevice();
	uint32_t queue_family = command_pool->GetFamily();
	Vulkan::Queue* queue = vulkan_device->GetQueue(queue_family, 0);
	queue->FlushCommandBuffer(command_buffer);
}

void Buffer::CopyFrom(const GHI::Resource* other)
{
	Device* vk_device = static_cast<Device*>(mDevice);
	Factory* vk_factory = static_cast<Factory*>(mDevice->GetFactory());
	Pool* vk_pool = vk_factory->GetPool();
	Vulkan::CommandPool* command_pool = vk_pool->GetVulkanCommandPool();
	Vulkan::CommandBuffer* command_buffer = command_pool->GetCommandBuffer(0);

	GHI::ResourceType type = other->GetType();

	if (type == GHI::ResourceType::BUFFER)
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

VkBufferUsageFlags Buffer::ConvertUsageFlag(void)
{
	VkBufferUsageFlags flags = 0;
	flags |= (mUsage.memoryType.read == TRUE) ? VK_BUFFER_USAGE_TRANSFER_SRC_BIT : 0;
	flags |= (mUsage.memoryType.write == TRUE) ? VK_BUFFER_USAGE_TRANSFER_DST_BIT : 0;
	flags |= (mUsage.bufferUsage.indexBuffer == TRUE) ? VK_BUFFER_USAGE_INDEX_BUFFER_BIT : 0;
	flags |= (mUsage.bufferUsage.vertexBuffer == TRUE) ? VK_BUFFER_USAGE_VERTEX_BUFFER_BIT : 0;
	flags |= (mUsage.bufferUsage.uniformBuffer == TRUE) ? VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT : 0;
	flags |= (mUsage.bufferUsage.storageBuffer == TRUE) ? VK_BUFFER_USAGE_STORAGE_BUFFER_BIT : 0;
	flags |= (mUsage.bufferUsage.indirectBuffer == TRUE) ? VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT : 0;
	return flags;
}

VkDescriptorType Buffer::GetDescriptorType(void)
{
	VkDescriptorType descriptor_type =
	(mUsage.bufferUsage.uniformBuffer == 1) ? VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER :
	(mUsage.bufferUsage.storageBuffer == 1) ? VK_DESCRIPTOR_TYPE_STORAGE_BUFFER :
	(mUsage.bufferUsage.uniformTexel == 1) ? VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER :
	(mUsage.bufferUsage.storageTexel == 1) ? VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER: VK_DESCRIPTOR_TYPE_MAX_ENUM;
	assert(descriptor_type != VK_DESCRIPTOR_TYPE_MAX_ENUM);
	return descriptor_type;
}

} /* namespace VK */
