/*
 * VKResourceContainer.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCELAYOUT_H_
#define SOURCE_RENDER_VK_VKRESOURCELAYOUT_H_

#include <VKResourceState.h>
#include "RenderResourceLayout.h"
#include <vector>

namespace VK
{
class Context;
class CommandList;
class PipelineLayout;
class ResourceLayout : public Render::ResourceLayout
{
public:
	explicit ResourceLayout(Context* context);
	virtual ~ResourceLayout(void);

public:
	void Binding(CommandList* list);

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
	std::vector<PipelineLayout*> mPipelineLayouts;
	std::vector<Vulkan::DescriptorSetLayout*> mDescriptorSetLayouts;
};

static inline ResourceLayout* StaticCast(Render::ResourceLayout* layout)
{
	return static_cast<ResourceLayout*>(layout);
}

static inline ResourceLayout* SaftyCast(Render::ResourceLayout* layout)
{
	return dynamic_cast<ResourceLayout*>(layout);
}

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCELAYOUT_H_ */
