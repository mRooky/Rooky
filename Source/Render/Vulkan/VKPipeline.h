/*
 * VKPipeline.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKPIPELINE_H_
#define SOURCE_RENDER_VK_VKPIPELINE_H_

#include "VKPipelineState.h"
#include "VKRender.h"
#include "../../Core/GHI/GHIPipeline.h"

namespace VK
{
class Device;
class Pipeline: public GHI::Pipeline
{
public:
	explicit Pipeline(Device* device);
	virtual ~Pipeline(void) override;

public:
	virtual void Create(GHI::PipelineState* state) override;

public:
	void CreateVulkanPipeline(void);

public:
	inline Vulkan::Pipeline* GetVulkanPipeline(void) const { return mPipeline; }

protected:
	Vulkan::Pipeline* mPipeline = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPIPELINE_H_ */
