/*
 * ResourceList.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCELIST_H_
#define SOURCE_RENDER_VK_VKRESOURCELIST_H_

#include "RenderResourceList.h"
#include "VKRender.h"
#include <vector>

namespace VK
{
class ResourceContainer;
class ResourceList: public Render::ResourceList
{
	friend class ResourceContainer;
public:
	explicit ResourceList(ResourceContainer* container);
	virtual ~ResourceList(void) override;

public:
	void Update(void);

public:
	inline Vulkan::DescriptorSet* GetDescriptorSet(void) const { return mDescriptorSet; }

public:
	static VkDescriptorType GetDescriptorType(Render::ResourceType type);

public:
	static void SetImageInfo(Render::Resource* resource, VkDescriptorImageInfo* info);
	static void SetBufferInfo(Render::Resource* resource, VkDescriptorBufferInfo* info);

protected:
	void WriteDescriptorSet(void);
	void UpdateDescriptorSet(void);

protected:
	ResourceContainer* mContainer = nullptr;

protected:
	Vulkan::DescriptorSet* mDescriptorSet = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCELIST_H_ */
