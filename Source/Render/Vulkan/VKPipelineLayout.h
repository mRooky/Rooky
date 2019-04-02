/*
 * VKPipelineLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKPIPELINELAYOUT_H_
#define SOURCE_RENDER_VK_VKPIPELINELAYOUT_H_

#include "RenderPipelineLayout.h"
#include "VKRender.h"
#include <vector>

namespace VK
{
class Device;
class BindingLayout;
class PipelineLayout: public Render::PipelineLayout
{
public:
	explicit PipelineLayout(Device* device);
	virtual ~PipelineLayout(void) override;

public:
	virtual void Create(Render::BindingLayout* layout) override;

public:
	void CreateVulkanPipelineLayout(void);

public:
	inline Vulkan::PipelineLayout* GetVulkanPipelineLayout(void) const { return mPipelineLayout; }

public:
	inline const std::vector<Vulkan::DescriptorSetLayout*>& GetLayouts(void) const { return mDescriptorSetLayouts; }

protected:
	Vulkan::PipelineLayout* mPipelineLayout = nullptr;
	std::vector<VkPushConstantRange> mConstantRanges;
	std::vector<Vulkan::DescriptorSetLayout*> mDescriptorSetLayouts;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPIPELINELAYOUT_H_ */
