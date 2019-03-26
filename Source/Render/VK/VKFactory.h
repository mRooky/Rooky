/*
 * VKFactory.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKFACTORY_H_
#define SOURCE_RENDER_VK_VKFACTORY_H_

#include "RenderFactory.h"
#include "VKRender.h"

namespace VK
{
class Context;
class Staging;
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
	virtual Render::VertexLayout* CreateVertexLayout(void) override;

public:
	virtual Render::BindingLayout* CreateBindingLayout(void) override;

public:
	inline Staging* GetStaging(void) const { return mStaging; }
	inline Vulkan::CommandPool* GetVulkanCommandPool(void) const { return mCommandPool; }

protected:
	void CreateDefaultPool(void);

protected:
	Staging* mStaging = nullptr;
	Vulkan::CommandPool* mCommandPool = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKFACTORY_H_ */
