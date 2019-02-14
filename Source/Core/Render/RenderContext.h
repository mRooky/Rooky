/*
 * RenderContext.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERCONTEXT_H_
#define SOURCE_CORE_RENDER_RENDERCONTEXT_H_

#include "PlatformWindow.h"
#include "RenderTypes.h"
#include "RenderFormat.h"
#include <vector>

namespace Render
{
class Image;
class Buffer;
class Object;
class Context
{
protected:
	Context(void);

public:
	virtual ~Context(void);

public:
	virtual void Create(void) = 0;

public:
	virtual Image* CreateImage(void) = 0;
	virtual Buffer* CreateBuffer(void) = 0;

public:
	virtual Format GetBestDepthStencilFormat(void) = 0;
	virtual uint32_t GetImageUsageFlag(uint32_t usage, bool read, bool write) = 0;
	virtual uint32_t GetUsageFlag(BufferUsageFlags usage, bool read, bool write) = 0;

};

Context* CreateContext(void);
void DestroyContext(Context* context);

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERCONTEXT_H_ */
