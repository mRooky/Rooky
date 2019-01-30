/*
 * VKMemory.h
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_XHIL_RENDER_VK_VULKAN_VKMEMORY_H_
#define SOURCE_XHIL_RENDER_VK_VULKAN_VKMEMORY_H_

#include "RenderMemory.h"
#include "VKRender.h"

namespace VK
{
class Context;
class Memory: public Render::Memory
{
public:
	explicit Memory(Context* context);
	virtual ~Memory(void) override;

public:
	virtual void Initialize(size_t size, uint32_t index, uint32_t property) override;

public:
	virtual void* Mapped(size_t offset, size_t range) override;
	virtual void UnMap(size_t offset, size_t range) override;

public:
	inline Vulkan::DeviceMemory* GetMemoryVK(void) const { return mMemory; }

protected:
	Vulkan::DeviceMemory* mMemory = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_XHIL_RENDER_VK_VULKAN_VKMEMORY_H_ */
