/*
 * VKBuffer.h
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKBUFFER_H_
#define SOURCE_RENDER_VK_VKBUFFER_H_

#include "../../Core/GHI/GHIBuffer.h"
#include "VKRender.h"

namespace VK
{
class Device;
class Buffer: public GHI::Buffer
{
public:
	explicit Buffer(Device* device);
	virtual ~Buffer(void) override;

public:
	virtual void Create(size_t size, const GHI::UsageType& usage) override;

public:
	virtual void* Map(size_t offset, size_t size) override;
	virtual void Unmap(size_t offset, size_t size) override;

public:
	virtual void Download(void* dst, size_t offset, size_t size) override;
	virtual void Upload(const void* src, size_t offset, size_t size) override;

public:
	virtual void CopyFrom(const GHI::Resource* other) override;

public:
	VkDescriptorBufferInfo GetDescriptorInfo(void) const;

public:
	inline Vulkan::Buffer* GetVulkanBuffer(void) const { return mBuffer; }
	inline Vulkan::DeviceMemory* GetVulkanMemory(void) const { return mMemory; }

public:
	static VkBufferUsageFlags ConvertUsageFlag(GHI::UsageType usage);
	static VkDescriptorType GetDescriptorType(const GHI::UsageType& usage);

private:
	void CreateVulkanBuffer(void);
	void AllocateVulkanMemory(void);

protected:
	Vulkan::Buffer* mBuffer = nullptr;
	Vulkan::DeviceMemory* mMemory = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKBUFFER_H_ */
