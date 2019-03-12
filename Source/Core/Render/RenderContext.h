/*
 * RenderContext.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERCONTEXT_H_
#define SOURCE_CORE_RENDER_RENDERCONTEXT_H_

#include "RenderFormat.h"
#include <vector>

namespace Render
{
class Factory;
class Context
{
protected:
	Context(void);

public:
	virtual ~Context(void);

public:
	virtual void Create(void) = 0;

public:
	inline Factory* GetFactory(void) const { return mFactory; }

protected:
	Factory* mFactory = nullptr;

public:
	virtual Format GetBestDepthStencilFormat(void) = 0;
};

Context* CreateContext(void);
void DestroyContext(Context* context);

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERCONTEXT_H_ */
