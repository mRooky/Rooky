/*
 * CoreScene.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESCENE_H_
#define SOURCE_CORE_CORESCENE_H_

#include "GHIClasses.h"
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
	inline GHI::SwapChain* GetSwapChain(void) const { return mSwapChain; }

public:
	inline size_t GetViewportCount(void) const { return mViewports.size(); }
	inline size_t GetRenderableCount(void) const { return mRenderables.size(); }

public:
	inline Viewport* GetViewport(size_t index) const { return mViewports.at(index); }
	inline Renderable* GetRenderable(size_t index) const { return mRenderables.at(index); }

protected:
	System* mSystem = nullptr;
	GHI::SwapChain* mSwapChain = nullptr;

protected:
	std::vector<Viewport*> mViewports;
	std::vector<Renderable*> mRenderables;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESCENE_H_ */
