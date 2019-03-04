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
class ResourceLayout;
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
	virtual void BindFrameBuffer(Render::FrameBuffer* frame, const Render::Rect2D& area) override;
	virtual void BindPipeline(Render::Pipeline* pipeline) override;
	virtual void SetViewport(uint32_t first, uint32_t count, const Render::Viewport* viewports) override;
	virtual void SetScissor(uint32_t first, uint32_t count, const Render::Rect2D* rects) override;
	// Resource Setting
	virtual void SetResource(uint32_t index, uint32_t bind, const Render::Resource& resource) override;
	// End Resource Setting
	virtual void Draw(Render::DrawCall* draw) override;
	virtual void EndPass(void) override;
	// End Draw Commands
	virtual void EndRecord(void) override;

public:
	inline Vulkan::CommandBuffer* GetCommandBufferVK(void) const { return mCommandBuffer; }

protected:
	ResourceLayout* mResourceLayout = nullptr;
	Vulkan::CommandBuffer* mCommandBuffer = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKCOMMANDLIST_H_ */
