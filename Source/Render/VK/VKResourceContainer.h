/*
 * VKResourceContainer.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCECONTAINER_H_
#define SOURCE_RENDER_VK_VKRESOURCECONTAINER_H_

#include "VKResourceList.h"
#include <vector>

namespace VK
{
class Context;
class CommandList;
class ResourceContainer
{
public:
	explicit ResourceContainer(Context* context);
	virtual ~ResourceContainer(void);

public:
	void Binding(CommandList* list);

public:
	Vulkan::DescriptorSet* AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings);

public:
	ResourceList* GetResourceList(size_t index);

public:
	inline size_t GetResourceListCount(void) const { return mResourceLists.size(); }

protected:
	void UpdatePipelineLayout(void);
	void CreateDescriptorPool(size_t max);

protected:
	Context* mContext = nullptr;
	std::vector<ResourceList> mResourceLists;

protected:
	Vulkan::DescriptorPool* mDescriptorPool = nullptr;
	Vulkan::PipelineLayout* mPipelineLayout = nullptr;
	std::vector<Vulkan::DescriptorSetLayout*> mDescriptorSetLayouts;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCECONTAINER_H_ */
