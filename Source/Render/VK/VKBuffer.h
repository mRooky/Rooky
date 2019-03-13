/*
 * VKBuffer.h
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKBUFFER_H_
#define SOURCE_RENDER_VK_VKBUFFER_H_

#include "RenderBuffer.h"
#include "VKRender.h"

namespace VK
{
class Context;
class Buffer: public Render::Buffer
{
public:
	explicit Buffer(Context* context);
	virtual ~Buffer(void) override;

public:
	virtual void Create(size_t size, const Render::ResourceUsage& usage) override;

public:
	virtual void Download(void* dst) override;
	virtual void Upload(const void* src) override;
	virtual void* Map(size_t offset, size_t size) override;
	virtual void Unmap(size_t offset, size_t size) override;

public:
	virtual void CopyFrom(const Render::Buffer* other) override;

public:
	VkDescriptorBufferInfo GetDescriptorInfo(void) const;

public:
	inline Vulkan::Buffer* GetVulkanBuffer(void) const { return mBuffer; }
	inline Vulkan::DeviceMemory* GetVulkanMemory(void) const { return mMemory; }

public:
	static VkBufferUsageFlags ConvertUsageFlag(Render::ResourceUsage usage);

private:
	void CreateBuffer(void);
	void AllocateMemory(void);

protected:
	Vulkan::Buffer* mBuffer = nullptr;
	Vulkan::DeviceMemory* mMemory = nullptr;
};

static inline Buffer* StaticCast(Render::Buffer* buffer)
{
	return static_cast<Buffer*>(buffer);
}

static inline Buffer* SaftyCast(Render::Buffer* buffer)
{
	return dynamic_cast<Buffer*>(buffer);
}

static inline const Buffer* StaticCast(const Render::Buffer* buffer)
{
	return static_cast<const Buffer*>(buffer);
}

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKBUFFER_H_ */
