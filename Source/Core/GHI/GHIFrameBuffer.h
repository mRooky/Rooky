/*
 * RenderFrameBuffer.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERFRAMEBUFFER_H_
#define SOURCE_CORE_GHI_RENDERFRAMEBUFFER_H_

#include "GHIFrameLayout.h"

namespace GHI
{
class RenderPass;
class FrameBuffer
{
protected:
	explicit FrameBuffer(RenderPass* pass);

public:
	virtual ~FrameBuffer(void);

public:
	virtual void Create(const FrameLayout& layout) = 0;

public:
	inline RenderPass* GetRenderPass(void) const
	{
		return mPass;
	}

	inline const FrameLayout& GetLayout(void) const
	{
		return mFrameLayout;
	}

protected:
	RenderPass* mPass = nullptr;
	FrameLayout mFrameLayout = {};
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERFRAMEBUFFER_H_ */
