/*
 * VulkanPipelineCache.cpp
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#include "VulkanPipelineCache.h"
#include "VulkanDevice.h"
#include <cassert>

namespace Vulkan
{

PipelineCache::PipelineCache(Device* device):
		DeviceObject(device)
{
}

PipelineCache::~PipelineCache(void)
{
	VkDevice device = mDevice->GetHandle();
	vkDestroyPipelineCache(device, m_cache, nullptr);
	m_cache = VK_NULL_HANDLE;
}

VkResult PipelineCache::Create(uint32_t size, const void* data)
{
	VkPipelineCacheCreateInfo pipeline_cache_create_info = PipelineCache::CreateInfo();
	pipeline_cache_create_info.initialDataSize = size;
	pipeline_cache_create_info.pInitialData = data;
	return Create(&pipeline_cache_create_info);
}

VkResult PipelineCache::Create(const VkPipelineCacheCreateInfo* info)
{
	mResult = vkCreatePipelineCache(mDevice->GetHandle(), info, nullptr, &m_cache);
	assert(mResult == VK_SUCCESS);
	return mResult;
}

VkPipelineCacheCreateInfo PipelineCache::CreateInfo(void)
{
	VkPipelineCacheCreateInfo pipeline_cache_create_info = {};
	pipeline_cache_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO;
	pipeline_cache_create_info.pNext = nullptr;
	pipeline_cache_create_info.flags = 0;
	pipeline_cache_create_info.initialDataSize = 0;
	pipeline_cache_create_info.pInitialData = nullptr;
	return pipeline_cache_create_info;
}

} /* namespace Vulkan */
