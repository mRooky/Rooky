/*
 * RenderPass.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERPASS_H_
#define SOURCE_CORE_RENDER_RENDERPASS_H_

#include "RenderObject.h"
#include "RenderFormat.h"
#include <vector>

namespace Render
{
class FrameBuffer;
class Pass: public Object
{
protected:
	explicit Pass(Device* device);

public:
	virtual ~Pass(void) override;

public:
	virtual void Create(void) = 0;

public:
	virtual FrameBuffer* CreateFrameBuffer(void) = 0;

public:
	void AppendFormat(Format format);
	void RemoveFormat(size_t index);

public:
	inline void SetDepthStencilFormat(Format format) { mDepthStencil = format; }

public:
	inline Format GetDepthStencilFormat(void) const { return mDepthStencil; }
	inline size_t GetFrameBufferCount(void) const { return mFrameBuffers.size(); }
	inline FrameBuffer* GetFrameBuffer(size_t index) const { return mFrameBuffers.at(index); }

protected:
	std::vector<Format> mFormats;
	std::vector<FrameBuffer*> mFrameBuffers;
	Format mDepthStencil = Format::FORMAT_UNDEFINED;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERPASS_H_ */
