/*
 * VKQueue.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKQUEUE_H_
#define SOURCE_RENDER_VK_VKQUEUE_H_

#include "RenderQueue.h"
#include "VKRender.h"

namespace VK
{
class Context;
class Queue: public Render::Queue
{
public:
	explicit Queue(Context* context);
	virtual ~Queue(void) override;

public:
	virtual void Create(uint32_t mIndex) override;

public:
	virtual void Submit(Render::CommandList* command) override;

public:
	inline Vulkan::Queue* GetVulkanQueue(void) const { return mQueue; }

protected:
	Vulkan::Queue* mQueue = nullptr;
};

static inline Queue* StaticCast(Render::Queue* queue) { return static_cast<Queue*>(queue); }
static inline Queue* SaftyCast(Render::Queue* queue) { return dynamic_cast<Queue*>(queue); }

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKQUEUE_H_ */
