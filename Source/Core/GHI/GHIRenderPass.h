/*
 * RenderPass.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERPASS_H_
#define SOURCE_CORE_GHI_RENDERPASS_H_

#include "GHIFormat.h"
#include "GHIObject.h"
#include "GHISubPass.h"
#include <vector>

namespace GHI
{
class Attachment;
class FrameBuffer;

class RenderPass: public Object
{
protected:
	explicit RenderPass(Device* device);

public:
	virtual ~RenderPass(void) override;

public:
	virtual void Create(size_t count) = 0;

public:
	virtual FrameBuffer* CreateFrameBuffer(void) = 0;

public:
	void AppendFormat(Format format);
	void RemoveFormat(size_t index);

public:
	inline void SetDepthStencilFormat(Format format)
	{
		mDepthStencil = format;
	}

public:
	inline Format GetDepthStencilFormat(void) const
	{
		return mDepthStencil;
	}

	inline size_t GetAttachmentFormatCount(void) const
	{
		return mFormats.size();
	}

	inline Format GetAttachmentFormat(size_t index) const
	{
		return mFormats.at(index);
	}

public:
	inline size_t GetFrameBufferCount(void) const
	{
		return mFrameBuffers.size();
	}

	inline FrameBuffer* GetFrameBuffer(size_t index) const
	{
		return mFrameBuffers.at(index);
	}

protected:
	std::vector<Format> mFormats;
	std::vector<FrameBuffer*> mFrameBuffers;
	Format mDepthStencil = Format::UNDEFINED;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERPASS_H_ */
