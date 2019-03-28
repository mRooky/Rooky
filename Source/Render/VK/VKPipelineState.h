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
class Device;
class PipelineState : public Render::PipelineState
{
public:
	explicit PipelineState(Device* device);
	virtual ~PipelineState(void) override;

public:
	virtual void Create(void) override;

public:
	inline const Vulkan::GraphicsPipelineInfo* GetGraphicsInfo(void) const { return &mGraphicsInfo; }

protected:
	void CreateVulkanLayoutInfo(void);
	void CreateVulkanViewportInfo(void);
	void CreateVulkanVertexInputInfo(void);
	void CreateVulkanRenderPassInfo(void);
	void CreateVulkanShaderStageInfo(void);
	void CreateVulkanColorBlendInfo(void);

protected:
	Vulkan::GraphicsPipelineInfo mGraphicsInfo;
};

}

#endif /* SOURCE_RENDER_VK_VKPIPELINESTATE_H_ */
