/*
 * RenderFrameBuffer.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_
#define SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_

#include "RenderObject.h"
#include <vector>

namespace Render
{
class Image;
class FrameBuffer: public Object
{
public:
	explicit FrameBuffer(Context* context);
	virtual ~FrameBuffer(void) override;

public:
	inline size_t GetAttachmentCount(void) const { return mAttachments.size(); }
	inline Image* GetAttachment(size_t index) const { return mAttachments.at(index); }

protected:
	std::vector<Image*> mAttachments;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERFRAMEBUFFER_H_ */
