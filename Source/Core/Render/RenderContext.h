/*
 * RenderContext.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERCONTEXT_H_
#define SOURCE_CORE_RENDER_RENDERCONTEXT_H_

#include "RenderEnum.h"
#include "PlatformWindow.h"
#include "RenderFormat.h"
#include "RenderClasses.h"
#include <vector>

namespace Render
{
class Context
{
protected:
	Context(void);

public:
	virtual ~Context(void);

public:
	virtual void Create(void) = 0;

public:
	virtual Pass* CreatePass(void) = 0;
	virtual Queue* CreateQueue(void) = 0;
	virtual Image* CreateImage(void) = 0;
	virtual Buffer* CreateBuffer(void) = 0;
	virtual SwapChain* CreateSwapChain(void) = 0;
	virtual CommandPool* CreateCommandPool(void) = 0;

public:
	virtual Format GetBestDepthStencilFormat(void) = 0;
	virtual uint32_t GetImageUsageFlag(uint32_t usage, bool read, bool write) = 0;

};

Context* CreateContext(void);
void DestroyContext(Context* context);

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERCONTEXT_H_ */
