/*
 * RenderContext.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERCONTEXT_H_
#define SOURCE_CORE_RENDER_RENDERCONTEXT_H_

namespace Render
{
class BufferManager;
class Context
{
protected:
	Context(void);

public:
	virtual ~Context(void);

public:
	virtual void Initialize(bool debug) = 0;

public:
	inline BufferManager* GetBufferManager(void) const { return mBufferManager; }

protected:
	BufferManager* mBufferManager = nullptr;
};

Context* CreateContext(void);
void DestroyContext(Context* context);

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERCONTEXT_H_ */
