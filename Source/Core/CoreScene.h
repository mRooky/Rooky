/*
 * CoreScene.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESCENE_H_
#define SOURCE_CORE_CORESCENE_H_

#include "RenderClasses.h"
#include "PlatformWindow.h"
#include <vector>

namespace Core
{
class System;
class Viewport;
class Renderable;
class Scene
{
public:
	Scene(void);
	virtual ~Scene(void);

public:
	void Draw(void);

public:
	void CreateSwapChain(Platform::Window* window);
	Viewport* CreateViewport(void);

public:
	void AddRenderable(Renderable* renderable);

public:
	inline System* GetSystem(void) const { return mSystem; }
	inline Render::SwapChain* GetSwapChain(void) const { return mSwapChain; }

protected:
	System* mSystem = nullptr;
	Render::SwapChain* mSwapChain = nullptr;

protected:
	std::vector<Viewport*> mViewports;
	std::vector<Renderable*> mRenderables;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESCENE_H_ */
