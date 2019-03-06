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
class Context;
class PipelineLayout: public Render::PipelineLayout
{
public:
	explicit PipelineLayout(Context* context);
	virtual ~PipelineLayout(void) override;

public:
	void Create(const std::vector<Vulkan::DescriptorSetLayout*>& layouts);

public:
	inline Vulkan::PipelineLayout* GetPipelineLayoutVK(void) const { return mPipelineLayout; }

public:
	inline const std::vector<Vulkan::DescriptorSetLayout*>& GetDescriptorSetLayout(void) const
	{
		return mDescriptorSetLayouts;
	}

protected:
	Vulkan::PipelineLayout* mPipelineLayout = nullptr;
	std::vector<VkPushConstantRange> mConstantRanges;
	std::vector<Vulkan::DescriptorSetLayout*> mDescriptorSetLayouts;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKPIPELINELAYOUT_H_ */
