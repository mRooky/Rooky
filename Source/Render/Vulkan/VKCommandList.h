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
	virtual void Submit(Render::Queue* queue) override;

public:
	virtual void Begin(void) override;
	// Draw Commands
	virtual void BeginPass(Render::Pass* pass, Render::FrameBuffer* frame, const Render::Rect2Di& area) override;
	// Fix Setup
	virtual void SetViewport(uint32_t first, uint32_t count, const Render::Viewport* viewports) override;
	virtual void SetScissor(uint32_t first, uint32_t count, const Render::Rect2Di* rects) override;
	// End Fix Setup
	// Resource Setting
	virtual void SetPipeline(Render::Pipeline* pipeline) override;
	virtual void SetBindingSet(uint32_t slot, Render::BindingSet* set) override;
	virtual void SetVertex(Render::Buffer* buffer, uint32_t binding, size_t offset) override;
	virtual void SetIndex(Render::Buffer* buffer, size_t offset, Render::IndexType type) override;
	// End Resource Setting
	virtual void Draw(Render::Draw* draw) override;
	virtual void EndPass(void) override;
	// End Draw Commands
	virtual void End(void) override;

public:
	inline Vulkan::CommandBuffer* GetVulkanCommandBuffer(void) const { return mCommandBuffer; }

private:
	void BindingResource(void);
	void DrawIndexed(Render::Draw* draw);

protected:
	Render::Pipeline* mPipeline = nullptr;
	Render::BindingLayout* mBindingLayout = nullptr;

protected:
	Vulkan::CommandBuffer* mCommandBuffer = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKCOMMANDLIST_H_ */