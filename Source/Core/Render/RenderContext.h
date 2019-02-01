/*
 * RenderContext.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERCONTEXT_H_
#define SOURCE_CORE_RENDER_RENDERCONTEXT_H_

#include "PlatformWindow.h"
#include <vector>

namespace Render
{
class Surface;
class BufferManager;
class Context
{
protected:
	Context(void);

public:
	virtual ~Context(void);

public:
	virtual void Initialize(const char* title) = 0;

public:
	inline Surface* GetSurface(void) const { return mSurface; }
	inline Platform::Window* GetWindow(void) const { return mWindow ;}
	inline BufferManager* GetBufferManager(void) const { return mBufferManager; }

protected:
	Surface* mSurface = nullptr;
	Platform::Window* mWindow = nullptr;
	BufferManager* mBufferManager = nullptr;
};

Context* CreateContext(void);
void DestroyContext(Context* context);

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERCONTEXT_H_ */
