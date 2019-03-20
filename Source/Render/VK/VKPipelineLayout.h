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
class BindingLayout;
class PipelineLayout: public Render::PipelineLayout
{
public:
	explicit PipelineLayout(BindingLayout* layout);
	virtual ~PipelineLayout(void) override;

public:
	void Create(const std::vector<Vulkan::DescriptorSetLayout*>& layouts);

public:
	inline Vulkan::PipelineLayout* GetVulkanPipelineLayout(void) const { return mPipelineLayout; }

public:
	inline const std::vector<Vulkan::DescriptorSetLayout*>& GetLayouts(void) const { return mDescriptorSetLayouts; }

protected:
	Vulkan::PipelineLayout* mPipelineLayout = nullptr;
	std::vector<VkPushConstantRange> mConstantRanges;
	std::vector<Vulkan::DescriptorSetLayout*> mDescriptorSetLayouts;
};

static inline PipelineLayout* StaticCast(Render::PipelineLayout* layout)
{
	return static_cast<PipelineLayout*>(layout);
}

static inline PipelineLayout* SaftyCast(Render::PipelineLayout* layout)
{
	return dynamic_cast<PipelineLayout*>(layout);
}

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPIPELINELAYOUT_H_ */
