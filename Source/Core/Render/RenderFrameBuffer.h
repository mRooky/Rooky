/*
 * RenderFrameBuffer.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_
#define SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_

#include "RenderMath.h"
#include <vector>

namespace Render
{
class Pass;
class Image;
class FrameBuffer
{
protected:
	explicit FrameBuffer(Pass* pass);

public:
	virtual ~FrameBuffer(void);

public:
	virtual void Create(const std::vector<Image*>& attachments, Image* depth) = 0;

public:
	void AppendAttachment(Image* attachment);
	void SetDepthStencil(Image* attachment);

public:
	inline Pass* GetRenderPass(void) const { return mPass; }
	inline Image* GetDepthStencil(void) const { return mDepthStencil; }

public:
	inline size_t GetAttachmentCount(void) const { return mAttachments.size(); }
	inline Image* GetAttachment(size_t index) const { return mAttachments.at(index); }

protected:
	Pass* mPass = nullptr;
	Image* mDepthStencil = nullptr;
	std::vector<Image*> mAttachments;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_ */
