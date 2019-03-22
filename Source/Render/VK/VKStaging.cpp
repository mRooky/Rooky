/*
 * VKStaging.cpp
 *
 *  Created on: Mar 22, 2019
 *      Author: rookyma
 */

#include "VKStaging.h"
#include "VKContext.h"
#include "VKBuffer.h"
#include "VKInline.h"

#include "UtilRelease.h"

#include "VulkanBuffer.h"

#include <cassert>
#include <iostream>

namespace VK
{

Staging::Staging(Context* context):
		mContext(context)
{
}

Staging::~Staging(void)
{
	std::cout << "Release Recycled Buffer ..." << std::endl;
	Util::Release(mBuffers);
	std::cout << "All Recycled Buffers Released" << std::endl;
}

Buffer* Staging::GetBuffer(size_t size, VkBufferUsageFlags usage)
{
	Buffer* buffer = SearchBuffer(size, usage);
	if (buffer == nullptr)
	{
		auto resource_usage = ConvertBufferUsageFlags(usage);
		resource_usage.allocate.CPUAccess = 1; // Must CPU Access
		buffer = new Buffer(mContext);
		buffer->Create(size, resource_usage);
		mBuffers.push_back(buffer);
	}
	return buffer;
}

Buffer* Staging::SearchBuffer(size_t size, VkBufferUsageFlags usage)
{
	for (auto buffer : mBuffers)
	{
		size_t buffer_size = buffer->GetSize();
		if (buffer_size > size)
		{
			auto vulkan_buffer = buffer->GetVulkanBuffer();
			auto buffer_usage = vulkan_buffer->GetUsage();
			if ((usage & buffer_usage) == usage)
			{
				return buffer;
			}
		}
	}
	return nullptr;
}

} /* namespace VK */
