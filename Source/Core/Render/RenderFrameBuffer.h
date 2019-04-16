/*
 * RenderFrameBuffer.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_
#define SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_

#include "RenderMath.h"
#include "RenderAttachment.h"

namespace Render
{
class Pass;
class FrameBuffer
{
protected:
	explicit FrameBuffer(Pass* pass);

public:
	virtual ~FrameBuffer(void);

public:
	virtual void Create(const Attachment& attachment) = 0;

public:
	inline Pass* GetRenderPass(void) const { return mPass; }
	inline const Attachment& GetAttachment(void) const { return mAttachment; }

protected:
	Pass* mPass = nullptr;
	Attachment mAttachment = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_ */
