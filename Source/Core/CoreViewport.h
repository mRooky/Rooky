/*
 * CoreViewport.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVIEWPORT_H_
#define SOURCE_CORE_COREVIEWPORT_H_

#include "RenderClasses.h"
#include "RenderMath.h"

namespace Core
{

class Viewport
{
public:
	Viewport(void);
	virtual ~Viewport(void);

public:
	void Initialize(Render::SwapChain* chain);

public:
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
