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
class Node;
class System;
class Viewport;
class Scene
{
public:
	Scene(void);
	virtual ~Scene(void);

public:
	void CreateSwapChain(Platform::Window* window);
	Viewport* CreateViewport(void);

public:
	inline Node* GetRootNode(void) const { return mRoot; }
	inline System* GetSystem(void) const { return mSystem; }
	inline GHI::SwapChain* GetSwapChain(void) const { return mSwapChain; }

public:
	inline size_t GetViewportCount(void) const { return mViewports.size(); }

public:
	inline Viewport* GetViewport(size_t index) const { return mViewports.at(index); }

protected:
	Node* mRoot = nullptr;
	System* mSystem = nullptr;
	GHI::SwapChain* mSwapChain = nullptr;

protected:
	std::vector<Viewport*> mViewports;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESCENE_H_ */
