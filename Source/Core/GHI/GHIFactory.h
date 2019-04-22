/*
 * RenderFactory.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERFACTORY_H_
#define SOURCE_CORE_GHI_RENDERFACTORY_H_

#include "GHIClasses.h"
#include "GHIObject.h"

namespace GHI
{

class Factory: public Object
{
protected:
	explicit Factory(Device* device);

public:
	virtual ~Factory(void) override;

public:
	virtual RenderPass* CreateRenderPass(void) = 0;
	virtual Image* CreateImage(void) = 0;
	virtual Buffer* CreateBuffer(void) = 0;
	virtual Shader* CreateShader(void) = 0;
	virtual SwapChain* CreateSwapChain(void) = 0;
	virtual CommandPool* CreateCommandPool(void) = 0;
	virtual Sampler* CreateSampler(void) = 0;
	virtual PipelineLayout* CreatePipelineLayout(void) = 0;
	virtual Pipeline* CreatePipeline(void) = 0;
	virtual BindingSet* CreateBindingSet(void) = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERFACTORY_H_ */
