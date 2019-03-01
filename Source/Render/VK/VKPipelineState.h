/*
 * VKPipelineState.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKPIPELINESTATE_H_
#define SOURCE_RENDER_VK_VKPIPELINESTATE_H_

#include "RenderPipelineState.h"
#include "VKRender.h"
#include "Pipeline/VulkanGraphicsPipelineInfo.h"

namespace VK
{
class Context;
class PipelineState : public Render::PipelineState
{
public:
	explicit PipelineState(Context* context);
	virtual ~PipelineState(void) override;

public:
	inline Vulkan::GraphicsPipelineInfo* GetGraphicsInfo(void) { return &mGraphicsInfo; }
	inline Vulkan::PipelineLayout* GetPipelineLayout(size_t index) const { return  mPipelineLayouts.at(index); }

protected:
	std::vector<Vulkan::PipelineLayout*> mPipelineLayouts;

protected:
	Vulkan::GraphicsPipelineInfo mGraphicsInfo;
	std::vector<VkPushConstantRange> m_constantRanges;
};

}

#endif /* SOURCE_RENDER_VK_VKPIPELINESTATE_H_ */
