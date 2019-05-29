/*
 * VKQueue.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKQUEUE_H_
#define SOURCE_RENDER_VK_VKQUEUE_H_

#include "VKRender.h"
#include "../../Core/GHI/GHIQueue.h"

namespace VK
{
class Device;
class Queue: public GHI::Queue
{
public:
	explicit Queue(Device* device);
	virtual ~Queue(void) override;

public:
	virtual void Create(uint32_t mIndex) override;

public:
	virtual void Submit(GHI::CommandList* command) override;

public:
	inline Vulkan::Queue* GetVulkanQueue(void) const { return mQueue; }

protected:
	Vulkan::Queue* mQueue = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKQUEUE_H_ */
