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
	virtual void Create(size_t size, uint32_t usage) override;
	virtual void Allocate(bool mappable) override;

public:
	virtual void CopyFrom(const Render::Buffer* other) override;

public:
	VkDescriptorBufferInfo GetDescriptorInfo(void) const;

public:
	inline Vulkan::Buffer* GetBufferVK(void) const { return mBuffer; }
	inline Vulkan::DeviceMemory* GetMemoryVK(void) const { return mMemory; }

public:
	static VkBufferUsageFlags ConvertUsageFlag(Render::BufferUsage usage);

protected:
	Vulkan::Buffer* mBuffer = nullptr;
	Vulkan::DeviceMemory* mMemory = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKBUFFER_H_ */
