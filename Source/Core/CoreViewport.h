/*
 * CoreViewport.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREVIEWPORT_H_
#define SOURCE_CORE_COREVIEWPORT_H_

#include "RenderClasses.h"

namespace Core
{

class Viewport
{
public:
	Viewport(void);
	virtual ~Viewport(void);

public:
	void Initialize(bool depthStencil);

public:
	void CreateDepthStencil(void);

public:
	inline Render::Image* GetDepthStencil(void) const { return mDepthStencil; }

protected:
	Render::Image* mDepthStencil = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREVIEWPORT_H_ */
