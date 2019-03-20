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
#include <vector>

namespace VK
{
class Context;
class Pipeline: public Render::Pipeline
{
public:
	explicit Pipeline(Context* context);
	virtual ~Pipeline(void) override;

public:
	virtual void Initialize(const Render::PipelineInfo& info) override;

public:
	void Update(void);

public:
	inline Vulkan::Pipeline* GetVulkanPipeline(void) const { return mCurrent; }

protected:
	Vulkan::Pipeline* mCurrent = nullptr;
	std::vector<Vulkan::Pipeline*> mPipelines;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPIPELINE_H_ */
