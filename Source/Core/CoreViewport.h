/*
 * CoreViewport.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVIEWPORT_H_
#define SOURCE_CORE_COREVIEWPORT_H_

#include "RenderExtent.hpp"
#include "RenderClasses.h"

namespace Core
{
class Scene;
class Camera;
class Thread;
class Viewport
{
public:
	explicit Viewport(Scene* scene);
	virtual ~Viewport(void);

public:
	void Draw(void);

public:
	void CreateThread(uint32_t count);
	void CreateDepthStencil(const Render::Extent2Di& extent);

public:
	inline Render::Image* GetDepthStencil(void) const { return mDepthStencil; }

public:
	inline Camera* GetCamera(void) const { return mCamera; }
	inline void SetCamera(Camera* camera) { mCamera = camera; }
	inline Thread* GetThread(void) const { return mThread; }

protected:
	Scene* mParent = nullptr;

protected:
	Camera* mCamera = nullptr;
	Thread* mThread = nullptr;

protected:
	Render::Image* mDepthStencil = nullptr;

};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVIEWPORT_H_ */
