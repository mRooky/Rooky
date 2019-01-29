/*
 * RenderFrameBuffer.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_
#define SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_

#include <vector>

namespace Render
{
class Pass;
class Image;
class FrameBuffer
{
public:
	explicit FrameBuffer(Pass* pass);
	virtual ~FrameBuffer(void);

public:
	inline Pass* GetPass(void) const { return mPass; }

public:
	inline size_t GetAttachmentCount(void) const { return mAttachments.size(); }
	inline Image* GetAttachment(size_t index) const { return mAttachments.at(index); }

protected:
	Pass* mPass = nullptr;
	std::vector<Image*> mAttachments;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_ */
