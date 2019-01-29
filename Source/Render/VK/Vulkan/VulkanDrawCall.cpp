/*
 * VulkanDrawCall.cpp
 *
 *  Created on: Sep 2, 2018
 *      Author: rookyma
 */

#include "VulkanDrawCall.h"
#include "VulkanBuffer.h"
#include "VulkanDeviceMemory.h"
#include "VulkanCommandBuffer.h"
#include "VulkanInline.h"
#include <cassert>

namespace Vulkan
{

DrawCall::DrawCall(void) = default;
DrawCall::~DrawCall(void) = default;

DrawDirect::DrawDirect(void) = default;
DrawDirect::~DrawDirect(void) = default;

DrawArray::DrawArray(void) = default;
DrawArray::~DrawArray(void) = default;

void DrawArray::Record(CommandBuffer* command)
{
	VkCommandBuffer handle = command->GetHandle();
	vkCmdDraw(handle, mVertexCount, mInstanceCount, mFirstVertex, mFirstInstance);
}

VkDrawIndirectCommand DrawArray::GetIndirectCommand(void) const
{
	VkDrawIndirectCommand indirect_command = {};
	indirect_command.vertexCount = mVertexCount;
	indirect_command.instanceCount = mInstanceCount;
	indirect_command.firstVertex = mFirstVertex;
	indirect_command.firstInstance = mFirstInstance;
	return indirect_command;
}

DrawIndexed::DrawIndexed(void) = default;
DrawIndexed::~DrawIndexed(void) = default;

void DrawIndexed::Record(CommandBuffer* command)
{
	VkCommandBuffer handle = command->GetHandle();
	vkCmdDrawIndexed(handle, mIndexCount, mInstanceCount, mFirstIndex, mVertexOffset, mFirstInstance);
}

VkDrawIndexedIndirectCommand DrawIndexed::GetIndirectCommand(void) const
{
	VkDrawIndexedIndirectCommand indirect_command = {};
	indirect_command.indexCount = mIndexCount;
	indirect_command.instanceCount = mInstanceCount;
	indirect_command.firstIndex = mFirstIndex;
	indirect_command.vertexOffset = mVertexOffset;
	indirect_command.firstInstance = mFirstInstance;
	return indirect_command;
}

DrawIndirect::DrawIndirect(void)
{
	mStride = sizeof(VkDrawIndirectCommand);
}

DrawIndirect::~DrawIndirect(void)
{
	Release(mBuffer);
	Release(m_memory);
}

void DrawIndirect::Record(CommandBuffer* command)
{
	VkCommandBuffer handle = command->GetHandle();
	vkCmdDrawIndirect(handle, mBuffer->GetHandle(), 0, mDrawCount, mStride);
}

void DrawIndirect::Create(Device* device, size_t size)
{
	assert(mBuffer == nullptr && m_memory == nullptr);
	mSize = size;
	mBuffer = Buffer::New(device);
	VkBufferUsageFlags usage = VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
	mBuffer->Create(size, usage);

	m_memory = DeviceMemory::New(device);
	m_memory->Allocate(mBuffer, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);
	mBuffer->BindMemory(m_memory, 0);
}

uint32_t DrawIndirect::Write(uint32_t offset, DrawArray* draw)
{
	assert(mBuffer != nullptr);
	VkDrawIndirectCommand indirect_command = draw->GetIndirectCommand();
	assert(mSize > offset + sizeof(indirect_command));
	mBuffer->WriteData(offset, sizeof(indirect_command), &indirect_command);
	return offset + sizeof(indirect_command);
}

DrawIndexedIndirect::DrawIndexedIndirect(void)
{
	mStride = sizeof(VkDrawIndexedIndirectCommand);
}

DrawIndexedIndirect::~DrawIndexedIndirect(void) = default;

uint32_t DrawIndexedIndirect::Write(uint32_t offset, DrawIndexed* draw)
{
	assert(mBuffer != nullptr);
	VkDrawIndexedIndirectCommand indirect_command = draw->GetIndirectCommand();
	assert(mSize > offset + sizeof(indirect_command));
	mBuffer->WriteData(offset, sizeof(indirect_command), &indirect_command);
	return offset + sizeof(indirect_command);
}

void DrawIndexedIndirect::Record(CommandBuffer* command)
{
	VkCommandBuffer handle = command->GetHandle();
	vkCmdDrawIndexedIndirect(handle, mBuffer->GetHandle(), 0, mDrawCount, mStride);
}

} /* namespace Vulkan */
