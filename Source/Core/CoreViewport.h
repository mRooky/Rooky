/*
 * CoreViewport.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVIEWPORT_H_
#define SOURCE_CORE_COREVIEWPORT_H_

#include "RenderClasses.h"
#include "PlatformWindow.h"

namespace Core
{

class Viewport
{
public:
	Viewport(void);
	virtual ~Viewport(void);

public:
	void Initailize(Platform::Window* window, bool depthStencil);

public:
	void CreateSwapChain(Platform::Window* window);
	void CreateDepthStencil(void);

public:
	inline Render::SwapChain* GetSwapChain(void) const { return mSwapChain; }
	inline Render::Image* GetDepthStencil(void) const { return mDepthStencil; }

protected:
	Render::Image* mDepthStencil = nullptr;
	Render::SwapChain* mSwapChain = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVIEWPORT_H_ */
