/*
 * VKCommandPool.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKCOMMANDPOOL_H_
#define SOURCE_RENDER_VK_VKCOMMANDPOOL_H_

#include "VKRender.h"
#include "../../Core/GHI/GHICommandPool.h"

namespace VK
{
class Device;
class CommandPool: public GHI::CommandPool
{
public:
	explicit CommandPool(Device* device);
	virtual ~CommandPool(void) override;

public:
	virtual void Create(void) override;

public:
	virtual GHI::CommandList* Allocate(bool level) override;

public:
	inline Vulkan::CommandPool* GetVulkanCommandPool(void) const { return mCommandPool; }

protected:
	Vulkan::CommandPool* mCommandPool = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKCOMMANDPOOL_H_ */
