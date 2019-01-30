/*
 * VKBuffer.h
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKHARDWAREBUFFER_H_
#define SOURCE_RENDER_VK_VKHARDWAREBUFFER_H_

#include "RenderHardwareBuffer.h"
#include "VKRender.h"

namespace VK
{
class Context;
class HardwareBuffer: public Render::HardwareBuffer
{
public:
	explicit HardwareBuffer(Context* context);
	virtual ~HardwareBuffer(void) override;

public:
	virtual void Initialize(size_t size, uint32_t usage) override;
	virtual void BindMemory(Render::Memory* memory, size_t offset) override;

public:
	VkDescriptorBufferInfo GetDescriptorInfo(void) const;

public:
	inline Vulkan::Buffer* GetBufferVK(void) const { return mBuffer; }

protected:
	Vulkan::Buffer* mBuffer = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKHARDWAREBUFFER_H_ */
