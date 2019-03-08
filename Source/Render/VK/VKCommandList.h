/*
 * CommandList.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKCOMMANDLIST_H_
#define SOURCE_RENDER_VK_VKCOMMANDLIST_H_

#include "RenderCommandList.h"
#include "VKRender.h"

namespace VK
{
class CommandPool;
class CommandList: public Render::CommandList
{
public:
	explicit CommandList(CommandPool* pool);
	virtual ~CommandList(void) override;

public:
	virtual void Create(bool primary) override;
	virtual void Submit(uint32_t index) override;

public:
	virtual void BeginRecord(void) override;
	// Draw Commands
	virtual void BeginPass(uint32_t index, Render::Pass* pass) override;
	// Fix Setup
	virtual void SetFrameBuffer(Render::FrameBuffer* frame, const Render::Rect2D& area) override;
	virtual void SetViewport(uint32_t first, uint32_t count, const Render::Viewport* viewports) override;
	virtual void SetScissor(uint32_t first, uint32_t count, const Render::Rect2D* rects) override;
	// End Fix Setup
	// Resource Setting
	virtual void SetPipeline(Render::Pipeline* pipeline) override;
	virtual void SetResourceLayout(Render::ResourceLayout* layout) override;
	// End Resource Setting
	virtual void Draw(Render::DrawCall* draw) override;
	virtual void EndPass(void) override;
	// End Draw Commands
	virtual void EndRecord(void) override;

public:
	inline Vulkan::CommandBuffer* GetCommandBufferVK(void) const { return mCommandBuffer; }

protected:
	Render::Pipeline* mPipeline = nullptr;
	Render::ResourceLayout* mResourceLayout = nullptr;

protected:
	Vulkan::CommandBuffer* mCommandBuffer = nullptr;
};

static inline CommandList* StaticCast(Render::CommandList* list)
{
	return static_cast<CommandList*>(list);
}

static inline CommandList* SaftyCast(Render::CommandList* list)
{
	return dynamic_cast<CommandList*>(list);
}

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKCOMMANDLIST_H_ */
