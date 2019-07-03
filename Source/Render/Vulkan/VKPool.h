/*
 * VKPool.h
 *
 *  Created on: Mar 27, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKPOOL_H_
#define SOURCE_RENDER_VK_VKPOOL_H_

#include "VKRender.h"
#include "../../Core/GHI/GHIResourceUsage.h"
#include <vector>

namespace VK
{
class Device;
class Buffer;
class Pool
{
public:
	explicit Pool(Device& device);
	virtual ~Pool(void);

public:
	Buffer* GetStageBuffer(size_t size);
	Buffer* GetBuffer(size_t size, GHI::ResourceUsage& usage);

public:
	Vulkan::DescriptorSet* AllocateDescriptorSet(const std::vector<VkDescriptorSetLayoutBinding>& bindings);
	Vulkan::DescriptorSet* AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings);

public:
	inline Device* GetDevice(void) const { return &mDevice; }

public:
	inline Vulkan::CommandPool* GetVulkanCommandPool(void) const { return mCommandPool; }
	inline Vulkan::DescriptorPool* GetVulkanDescriptorPool(void) const { return mDescriptorPool; }

protected:
	void CreateCommandPool(void);
	void CreateDescriptorPool(size_t max);

protected:
	Buffer* SearchBuffer(size_t size, GHI::ResourceUsage& usage);

protected:
	Device& mDevice;
	std::vector<Buffer*> mBuffers;

protected:
	Vulkan::CommandPool* mCommandPool = nullptr;
	Vulkan::DescriptorPool* mDescriptorPool = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPOOL_H_ */
