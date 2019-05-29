/*
 * VKPipelineState.h
 *
 *  Created on: Feb 18, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKPIPELINESTATE_H_
#define SOURCE_RENDER_VK_VKPIPELINESTATE_H_

#include "../../Core/GHI/GHIClasses.h"
#include "../../Platform/Vulkan/Pipeline/VulkanGraphicsPipelineInfo.h"

namespace VK
{
class Device;
class PipelineState
{
public:
	PipelineState(void);
	~PipelineState(void);

public:
	void Create(const GHI::PipelineState* state);

public:
	inline bool IsValid(void) const { return mValid; }
	inline const Vulkan::GraphicsPipelineInfo* GetGraphicsInfo(void) const { return &mGraphicsInfo; }

protected:
	void CreateVulkanLayoutInfo(void);
	void CreateVulkanViewportInfo(void);
	void CreateVulkanVertexInputInfo(void);
	void CreateVulkanRenderPassInfo(void);
	void CreateVulkanShaderStageInfo(void);
	void CreateVulkanColorBlendInfo(bool blend = false);
	void CreateVulkanDepthStencil(void);

protected:
	bool mValid = false;
	Vulkan::GraphicsPipelineInfo mGraphicsInfo;
	const GHI::PipelineState* mState = nullptr;
};

}

#endif /* SOURCE_RENDER_VK_VKPIPELINESTATE_H_ */
