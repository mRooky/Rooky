/*
 * VKPipeline.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKPIPELINE_H_
#define SOURCE_RENDER_VK_VKPIPELINE_H_

#include "RenderPipeline.h"
#include "VKPipelineState.h"
#include "VKRender.h"

namespace VK
{
class Device;
class Pipeline: public Render::Pipeline
{
public:
	explicit Pipeline(Device* device);
	virtual ~Pipeline(void) override;

public:
	virtual void Create(Render::PipelineState* state) override;

public:
	void CreateVulkanPipeline(void);

public:
	inline Vulkan::Pipeline* GetVulkanPipeline(void) const { return mPipeline; }

protected:
	Vulkan::Pipeline* mPipeline = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPIPELINE_H_ */
