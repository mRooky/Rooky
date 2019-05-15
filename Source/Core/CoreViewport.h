/*
 * CoreViewport.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVIEWPORT_H_
#define SOURCE_CORE_COREVIEWPORT_H_

#include "GHIClasses.h"
#include "CorePipeline.h"
#include "MathViewport.h"

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
	void Create(const Math::Rect2Di& rect);

public:
	void Draw(void);

public:
	void CreateThread(uint32_t count);

public:
	inline Camera* GetCamera(void) const { return mCamera; }

public:
	inline Thread* GetThread(void) const { return mThread; }

protected:
	void DrawScene(void);

protected:
	Scene* mParent = nullptr;

protected:
	Camera* mCamera = nullptr;
	Thread* mThread = nullptr;

protected:
	ComputePipeline mComputePipeline = {};
	GraphicsPipeline mGraphicsPipeline = {};

protected:
	Math::Viewport mViewport;

};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVIEWPORT_H_ */
