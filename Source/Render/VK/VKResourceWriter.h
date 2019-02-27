/*
 * VKDescriptorPool.h
 *
 *  Created on: Feb 27, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCEWRITER_H_
#define SOURCE_RENDER_VK_VKRESOURCEWRITER_H_

#include "VKResourceSet.h"

#include <vector>

namespace VK
{
class Context;
class CommandList;
class ResourceWriter
{
public:
	explicit ResourceWriter(Context* context);
	virtual ~ResourceWriter(void);

public:
	void Binding(CommandList* list);

public:
	Vulkan::DescriptorSet* AllocateDescriptorSet(uint32_t count, const VkDescriptorSetLayoutBinding* bindings);

public:
	ResourceSet* CreateResourceSet(void);

public:
	inline size_t GetResourceSetCount(void) const { return mResourceSets.size(); }
	inline ResourceSet* GetResourceSet(size_t index) { return &mResourceSets.at(index); }

public:
	inline Vulkan::DescriptorPool* GetDescriptorPool(void) const { return mDescriptorPool; }

protected:
	void CreateDescriptorPool(size_t max);

protected:
	Context* mContext = nullptr;
	std::vector<ResourceSet> mResourceSets;
	Vulkan::DescriptorPool* mDescriptorPool = nullptr;
	Vulkan::PipelineLayout* mPipelineLayout = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCEWRITER_H_ */
