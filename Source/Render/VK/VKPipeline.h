/*
 * VKPipeline.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKPIPELINE_H_
#define SOURCE_RENDER_VK_VKPIPELINE_H_

#include "RenderPipeline.h"
#include "VKRender.h"

namespace VK
{
class PipelineState;
class Pipeline: public Render::Pipeline
{
public:
	explicit Pipeline(PipelineState* state);
	virtual ~Pipeline(void) override;

public:
	virtual void Initialize(Render::Pass* pass, uint32_t index) override;

public:
	inline Vulkan::Pipeline* GetPipelineVK(void) const { return mPipeline; }
	inline Vulkan::PipelineCache* GetPipelineCacheVK(void) const { return mPipelineCache; }
	inline Vulkan::PipelineLayout* GetPipelineLayoutVK(void) const { return mPipelineLayout; }

public:
	void CreateCache(Vulkan::PipelineCache* cache = nullptr);

protected:
	Vulkan::Pipeline* mPipeline = nullptr;
	Vulkan::PipelineCache* mPipelineCache = nullptr;
	Vulkan::PipelineLayout* mPipelineLayout = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPIPELINE_H_ */
