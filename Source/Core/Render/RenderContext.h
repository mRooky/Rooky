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
class Context
{
protected:
	Context(void);

public:
	virtual ~Context(void);

public:
	virtual void Create(Platform::Window* mWindow) = 0;

public:
	inline Surface* GetSurface(void) const { return mSurface; }

protected:
	Surface* mSurface = nullptr;
};

Context* CreateContext(void);
void DestroyContext(Context* context);

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERCONTEXT_H_ */
