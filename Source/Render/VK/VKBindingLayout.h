/*
 * VKResourceContainer.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKBINDINGLAYOUT_H_
#define SOURCE_RENDER_VK_VKBINDINGLAYOUT_H_

#include "RenderBindingLayout.h"
#include "VKBindingState.h"
#include <vector>

namespace VK
{
class Context;
class CommandList;
class PipelineLayout;
class BindingLayout : public Render::BindingLayout
{
public:
	explicit BindingLayout(Context* context);
	virtual ~BindingLayout(void);

public:
	virtual Render::PipelineLayout* Update(void) override;
	virtual Render::BindingState* CreateState(void) override;

public:
	void Binding(CommandList* list);
	void SetBindingState(uint32_t index, BindingState* state);

public:
	Vulkan::DescriptorSet* AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings);

public:
	void UpdatePipelineLayout(void);

public:
	inline Vulkan::DescriptorPool* GetDescriptorPool(void) const { return mDescriptorPool; }

protected:
	void CreateDescriptorPool(size_t max);
	PipelineLayout* GetPipelineLayout(const std::vector<Vulkan::DescriptorSetLayout*>& layouts);

protected:
	Vulkan::DescriptorPool* mDescriptorPool = nullptr;

protected:
	std::vector<BindingState*> mBindingStates;
	std::vector<PipelineLayout*> mPipelineLayouts;
	std::vector<Vulkan::DescriptorSetLayout*> mDescriptorSetLayouts;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKBINDINGLAYOUT_H_ */
