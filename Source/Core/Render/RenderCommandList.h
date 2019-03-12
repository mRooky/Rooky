/*
 * RenderCommandList.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERCOMMANDLIST_H_
#define SOURCE_CORE_RENDER_RENDERCOMMANDLIST_H_

#include "RenderClasses.h"
#include "RenderMath.h"
#include "RenderEnum.h"
#include "RenderResource.h"
#include "RenderResourceLayout.h"
#include "RenderPipelineDescription.h"

namespace Render
{
class CommandList
{
	friend class CommandPool;
protected:
	explicit CommandList(CommandPool* pool);
	virtual ~CommandList(void);

public:
	virtual void Create(bool level) = 0;
	virtual void Submit(uint32_t index) = 0;

public:
	virtual void BeginRecord(void) = 0;
	virtual void BeginPass(uint32_t index, Pass* pass) = 0;
	// Fix Setup
	virtual void SetFrameBuffer(FrameBuffer* frame, const Rect2D& area) = 0;
	virtual void SetViewport(uint32_t first, uint32_t count, const Viewport* viewports) = 0;
	virtual void SetScissor(uint32_t first, uint32_t count, const Rect2D* rects) = 0;
	// End Fix Setup
	// Resource Setup
	virtual void SetPipeline(Pipeline* pipeline) = 0;
	virtual void SetResourceLayout(ResourceLayout* layout) = 0;
	virtual void SetResourceState(uint32_t index, ResourceState* state) = 0;
	virtual void Draw(DrawCall* draw) = 0;
	// End Resource Setup
	virtual void EndPass(void) = 0;
	virtual void EndRecord(void) = 0;

public:
	inline CommandPool* GetCommandPool(void) const { return mCommandPool; }

protected:
	CommandPool* mCommandPool = nullptr;

protected:
	PipelineDescription mPipelineDescription = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERCOMMANDLIST_H_ */
