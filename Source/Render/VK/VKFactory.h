/*
 * VKFactory.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKFACTORY_H_
#define SOURCE_RENDER_VK_VKFACTORY_H_

#include "RenderFactory.h"

namespace VK
{
class Context;
class Factory: public Render::Factory
{
public:
	explicit Factory(Context* context);
	virtual ~Factory(void) override;

public:
	virtual Render::Pass* CreatePass(void) override;
	virtual Render::Queue* CreateQueue(void) override;
	virtual Render::Image* CreateImage(void) override;
	virtual Render::Buffer* CreateBuffer(void) override;
	virtual Render::Shader* CreateShader(void) override;
	virtual Render::SwapChain* CreateSwapChain(void) override;
	virtual Render::CommandPool* CreateCommandPool(void) override;
	virtual Render::Declaration* CreateDeclaration(void) override;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKFACTORY_H_ */
