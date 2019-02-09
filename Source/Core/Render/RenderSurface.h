/*
 * RenderSwapChain.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSWAPCHAIN_H_
#define SOURCE_CORE_RENDER_RENDERSWAPCHAIN_H_

#include "RenderObject.h"
#include "PlatformWindow.h"

namespace Render
{
class Surface: public Object
{
protected:
	explicit Surface(Context* context);

public:
	virtual ~Surface(void) override;

public:
	virtual void Create(Platform::Window* window) = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSWAPCHAIN_H_ */
