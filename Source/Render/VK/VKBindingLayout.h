/*
 * VKResourceContainer.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKBINDINGLAYOUT_H_
#define SOURCE_RENDER_VK_VKBINDINGLAYOUT_H_

#include "RenderBindingLayout.h"
#include "VKBindingSet.h"
#include <vector>

namespace VK
{
class Device;
class CommandList;
class PipelineLayout;
class BindingLayout : public Render::BindingLayout
{
public:
	explicit BindingLayout(Device* device);
	virtual ~BindingLayout(void);

public:
	virtual void Create(void) override;

public:
	virtual Render::BindingSet* CreateSet(void) override;

public:
	virtual void AppendBindingSet(const Render::BindingSet* set) override;
	virtual void SetBindingSet(size_t index, const Render::BindingSet* set) override;

public:
	void Binding(CommandList* list);

public:
	Vulkan::DescriptorSet* AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings);

public:
	inline Vulkan::DescriptorPool* GetVulkanDescriptorPool(void) const { return mDescriptorPool; }

protected:
	void CreateDescriptorPool(size_t max);

protected:
	std::vector<Vulkan::DescriptorSet*> mDescriptorSets;

protected:
	Vulkan::DescriptorPool* mDescriptorPool = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKBINDINGLAYOUT_H_ */
