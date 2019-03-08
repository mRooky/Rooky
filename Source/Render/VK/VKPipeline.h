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
class Context;
class Pipeline: public Render::Pipeline
{
public:
	explicit Pipeline(Context* context);
	virtual ~Pipeline(void) override;

public:
	virtual void Initialize(const Render::PipelineTraits& traits) override;

public:
	inline Vulkan::Pipeline* GetPipelineVK(void) const { return mPipeline; }
	inline Vulkan::PipelineCache* GetPipelineCacheVK(void) const { return mPipelineCache; }

public:
	void CreateCache(Vulkan::PipelineCache* cache = nullptr);

protected:
	bool mOwnCache = false;

protected:
	Vulkan::Pipeline* mPipeline = nullptr;
	Vulkan::PipelineCache* mPipelineCache = nullptr;
};

static inline Pipeline* StaticCast(Render::Pipeline* pipeline)
{
	return static_cast<Pipeline*>(pipeline);
}

static inline Pipeline* SaftyCast(Render::Pipeline* pipeline)
{
	return dynamic_cast<Pipeline*>(pipeline);
}

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPIPELINE_H_ */
