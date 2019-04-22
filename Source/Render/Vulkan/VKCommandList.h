/*
 * CommandList.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKCOMMANDLIST_H_
#define SOURCE_RENDER_VK_VKCOMMANDLIST_H_

#include "GHICommandList.h"
#include "VKRender.h"

namespace VK
{
class CommandPool;
class CommandList: public GHI::CommandList
{
public:
	explicit CommandList(CommandPool* pool);
	virtual ~CommandList(void) override;

public:
	virtual void Create(bool primary) override;

public:
	virtual void Begin(void) override;
	// Draw Commands
	virtual void BeginPass(GHI::RenderPass* pass, GHI::FrameBuffer* frame, const Math::Rect2Di& area) override;
	// Fix Setup
	virtual void SetViewport(uint32_t first, uint32_t count, const Math::Viewport* viewports) override;
	virtual void SetScissor(uint32_t first, uint32_t count, const Math::Rect2Di* rects) override;
	// End Fix Setup
	// Resource Setting
	virtual void SetPipeline(GHI::Pipeline* pipeline) override;
	virtual void SetBindingSet(uint32_t slot, GHI::BindingSet* set) override;
	virtual void SetVertex(GHI::Resource* buffer, uint32_t binding, size_t offset) override;
	virtual void SetIndex(GHI::Resource* buffer, size_t offset, GHI::IndexType type) override;
	// End Resource Setting
	virtual void Draw(GHI::Draw* draw) override;
	virtual void EndPass(void) override;
	// End Draw Commands
	virtual void End(void) override;

public:
	inline Vulkan::CommandBuffer* GetVulkanCommandBuffer(void) const { return mCommandBuffer; }

private:
	void BindingResource(void);
	void DrawIndexed(GHI::Draw* draw);

protected:
	GHI::Pipeline* mPipeline = nullptr;
	GHI::BindingLayout* mBindingLayout = nullptr;

protected:
	Vulkan::CommandBuffer* mCommandBuffer = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKCOMMANDLIST_H_ */
