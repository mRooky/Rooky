/*
 * RenderFactory.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERFACTORY_H_
#define SOURCE_CORE_RENDER_RENDERFACTORY_H_

#include "RenderObject.h"
#include "RenderClasses.h"

namespace Render
{

class Factory: public Object
{
protected:
	explicit Factory(Context* context);

public:
	virtual ~Factory(void) override;

public:
	virtual Pass* CreatePass(void) = 0;
	virtual Queue* CreateQueue(void) = 0;
	virtual Image* CreateImage(void) = 0;
	virtual Buffer* CreateBuffer(void) = 0;
	virtual Shader* CreateShader(void) = 0;
	virtual SwapChain* CreateSwapChain(void) = 0;
	virtual CommandPool* CreateCommandPool(void) = 0;
	virtual Declaration* CreateDeclaration(void) = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERFACTORY_H_ */
