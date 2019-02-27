/*
 * VKResourceSet.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCESET_H_
#define SOURCE_RENDER_VK_VKRESOURCESET_H_

#include "RenderResourceSet.h"
#include "VKRender.h"

namespace VK
{
class CommandList;
class ResourceSet: public Render::ResourceSet
{
	friend class CommandList;
protected:
	ResourceSet(void);
	virtual ~ResourceSet(void) override;

public:
	void Binding(CommandList* list);

public:
	inline Vulkan::DescriptorSet* GetDescriptorSet(void) const { return mDescriptorSet; }

protected:
	void UpdateDescriptorSet(void);

protected:
	std::vector<VkWriteDescriptorSet> mWrites;
	Vulkan::DescriptorSet* mDescriptorSet = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCESET_H_ */
