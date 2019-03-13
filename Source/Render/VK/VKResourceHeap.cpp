/*
 * VKHeap.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: rookyma
 */

#include "VKResourceHeap.h"
#include "VKBuffer.h"
#include "UtilRelease.h"

#include "VulkanBuffer.h"

#include <cassert>

namespace VK
{

ResourceHeap::ResourceHeap(Context* context):
		mContext(context)
{
	assert(mContext != nullptr);
}

ResourceHeap::~ResourceHeap(void)
{
	mContext = nullptr;
	Util::Release(mBuffers);
}

Buffer* ResourceHeap::AcquireBuffer(size_t size, VkBufferUsageFlags usage, bool cpu)
{
	Buffer* buffer = BufferFind(size, usage, cpu);
	if (buffer == nullptr)
	{
		auto resource_usage = Render::ResourceUsage::GetBufferUsage(cpu);
		buffer = new Buffer(mContext);
		buffer->Create(size, resource_usage);
		mBuffers.push_back(buffer);
	}
	return buffer;
}

Buffer* ResourceHeap::BufferFind(size_t size, VkBufferUsageFlags usage, bool cpu)
{
	for (auto buffer : mBuffers)
	{
		size_t buffer_size = buffer->GetSize();
		bool access_cpu = buffer->GetUsage().AccessCPU();
		if (buffer_size > size && access_cpu == cpu)
		{
			auto vulkan_buffer = buffer->GetVulkanBuffer();
			auto& info = vulkan_buffer->GetInfo();
			auto& buffer_usage = info.usage;
			if (usage & buffer_usage)
			{
				return buffer;
			}
		}
	}
	return nullptr;
}

} /* namespace VK */
