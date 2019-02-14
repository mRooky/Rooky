/*
 * CoreViewport.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVIEWPORT_H_
#define SOURCE_CORE_COREVIEWPORT_H_

#include "CoreObject.h"

#include "RenderClasses.h"
#include "RenderMath.h"
#include "PlatformWindow.h"

namespace Core
{
class System;
class Viewport : public Object
{
public:
	explicit Viewport(System* system);
	virtual ~Viewport(void);

public:
	void Create(Platform::Window* window);
	void CreateDepthStencil(const Render::Extent2& extent);

public:
	inline Render::SwapChain* GetSwapChain(void) const { return mSwapChain; }
	inline Render::Image* GetDepthStencil(void) const { return mDepthStencil; }

protected:
	Render::SwapChain* mSwapChain = nullptr;

protected:
	Render::Image* mDepthStencil = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVIEWPORT_H_ */
