/*
 * VKFactory.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKFACTORY_H_
#define SOURCE_RENDER_VK_VKFACTORY_H_

#include "GHIFactory.h"
#include "VKRender.h"

namespace VK
{
class Device;
class Pool;
class Factory: public GHI::Factory
{
public:
	explicit Factory(Device* device);
	virtual ~Factory(void) override;

public:
	virtual GHI::RenderPass* CreateRenderPass(void) override;
	virtual GHI::Image* CreateImage(void) override;
	virtual GHI::Buffer* CreateBuffer(void) override;
	virtual GHI::Shader* CreateShader(void) override;
	virtual GHI::SwapChain* CreateSwapChain(void) override;
	virtual GHI::CommandPool* CreateCommandPool(void) override;
	virtual GHI::Sampler* CreateSampler(void) override;
	virtual GHI::PipelineLayout* CreatePipelineLayout(void) override;
	virtual GHI::Pipeline* CreatePipeline(void) override;
	virtual GHI::BindingSet* CreateBindingSet(void) override;

public:
	inline Pool* GetPool(void) const { return mPool; }

protected:
	Pool* mPool = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKFACTORY_H_ */
