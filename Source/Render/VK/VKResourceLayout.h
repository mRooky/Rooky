/*
 * VKResourceContainer.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCELAYOUT_H_
#define SOURCE_RENDER_VK_VKRESOURCELAYOUT_H_

#include "RenderResourceLayout.h"
#include "VKResourceList.h"
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
	virtual Render::ResourceList* GetResourceList(size_t index) override;

public:
	virtual Render::PipelineLayout* UpdatePipelineLayout(void) override;

public:
	inline size_t GetResourceListCount(void) const { return mResourceLists.size(); }

public:
	inline Vulkan::DescriptorPool* GetDescriptorPool(void) const { return mDescriptorPool; }

protected:
	void CreateDescriptorPool(size_t max);

protected:
	std::vector<ResourceList> mResourceLists;

protected:
	Vulkan::DescriptorPool* mDescriptorPool = nullptr;

protected:
	std::vector<PipelineLayout*> mPipelineLayouts;
	std::vector<Vulkan::DescriptorSetLayout*> mDescriptorSetLayouts;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCELAYOUT_H_ */
