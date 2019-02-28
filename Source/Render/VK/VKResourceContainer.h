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
	ResourceList* CreateResourceList(void);

public:
	inline size_t GetResourceListCount(void) const { return mResourceLists.size(); }
	inline ResourceList* GetResourceList(size_t index) { return &mResourceLists.at(index); }

protected:
	void CreateDescriptorPool(size_t max);

protected:
	Context* mContext = nullptr;
	std::vector<ResourceList> mResourceLists;
	Vulkan::DescriptorPool* mDescriptorPool = nullptr;
	Vulkan::PipelineLayout* mPipelineLayout = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCECONTAINER_H_ */
