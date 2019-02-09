/*
 * VKCommandPool.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKCOMMANDPOOL_H_
#define SOURCE_RENDER_VK_VKCOMMANDPOOL_H_

#include "RenderCommandPool.h"
#include "VKRender.h"

namespace VK
{
class Context;
class CommandPool: public Render::CommandPool
{
public:
	explicit CommandPool(Context* context);
	virtual ~CommandPool(void) override;

public:
	virtual void Create(void) override;

public:
	virtual Render::CommandList* Allocate(bool level) override;

public:
	inline Vulkan::CommandPool* GetCommandPoolVK(void) const { return mCommandPool; }

protected:
	Vulkan::CommandPool* mCommandPool = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKCOMMANDPOOL_H_ */
