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
	void CreateCache(void);

public:
	inline Vulkan::PipelineCache* GetCache(void) const { return m_pipelineCache; }
	inline Vulkan::PipelineLayout* GetLayout(void) const { return  m_pipelineLayout; }
	inline Vulkan::GraphicsPipelineInfo* GetGraphicsInfo(void) { return &mGraphicsInfo; }

private:
	Vulkan::PipelineCache* m_pipelineCache = nullptr;
	Vulkan::PipelineLayout* m_pipelineLayout = nullptr;

protected:
	Vulkan::GraphicsPipelineInfo mGraphicsInfo;
	std::vector<VkPushConstantRange> m_constantRanges;
};

}

#endif /* SOURCE_RENDER_VK_VKPIPELINESTATE_H_ */
