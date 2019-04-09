/*
 * CoreViewport.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVIEWPORT_H_
#define SOURCE_CORE_COREVIEWPORT_H_

#include "CoreInterface.h"
#include "RenderExtent.hpp"
#include "RenderClasses.h"
#include "PlatformWindow.h"

namespace Core
{
class Camera;
class System;
class Viewport : public Interface
{
public:
	explicit Viewport(System* system);
	virtual ~Viewport(void);

public:
	void CreateSwapChain(Platform::Window* window);
	void CreateDepthStencil(const Render::Extent2Di& extent);

public:
	inline Render::SwapChain* GetSwapChain(void) const { return mSwapChain; }
	inline Render::Image* GetDepthStencil(void) const { return mDepthStencil; }

public:
	inline Camera* GetCamera(void) const { return mCamera; }
	inline void SetCamera(Camera* camera) { mCamera = camera; }

public:
	Camera* mCamera = nullptr;

protected:
	Render::Image* mDepthStencil = nullptr;
	Render::SwapChain* mSwapChain = nullptr;

};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVIEWPORT_H_ */
