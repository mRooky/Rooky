/*
 * RenderCommandList.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERCOMMANDLIST_H_
#define SOURCE_CORE_GHI_RENDERCOMMANDLIST_H_

#include <MathRect.h>
#include "GHIBinding.hpp"
#include "GHIBindingLayout.h"
#include "GHIClasses.h"
#include "GHIEnum.h"
#include "MathDefine.h"
#include "MathViewport.h"

namespace GHI
{
class CommandList
{
	friend class CommandPool;
protected:
	explicit CommandList(CommandPool* pool);
	virtual ~CommandList(void);

public:
	virtual void Create(bool level) = 0;

public:
	void Submit(Queue* queue);
	void Submit(uint32_t index);

public:
	virtual void Begin(void) = 0;
	virtual void BeginPass(RenderPass* pass, FrameBuffer* frame, const Math::Rect2Di& area) = 0;
	// Fix Setup
	virtual void SetViewport(uint32_t first, uint32_t count, const Math::Viewport* viewports) = 0;
	virtual void SetScissor(uint32_t first, uint32_t count, const Math::Rect2Di* rects) = 0;
	// End Fix Setup
	// Resource Setup
	virtual void SetPipeline(Pipeline* pipeline) = 0;
	virtual void SetBindingSet(uint32_t slot, BindingSet* set) = 0;
	virtual void SetVertex(Resource* buffer, uint32_t binding, size_t offset) = 0;
	virtual void SetIndex(Resource* buffer, size_t offset, IndexType type) = 0;
	virtual void Draw(Draw* draw) = 0;
	// End Resource Setup
	virtual void EndPass(void) = 0;
	virtual void End(void) = 0;

public:
	inline CommandPool* GetCommandPool(void) const { return mCommandPool; }

protected:
	CommandPool* mCommandPool = nullptr;

};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERCOMMANDLIST_H_ */
