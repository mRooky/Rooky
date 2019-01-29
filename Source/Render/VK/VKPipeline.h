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
	inline Vulkan::Pipeline* GetPipelineVK(void) const { return mPipeline; }

protected:
	Vulkan::Pipeline* mPipeline = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPIPELINE_H_ */
