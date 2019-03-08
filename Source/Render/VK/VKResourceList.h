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

namespace VK
{

class ResourceLayout;
class ResourceList : public Render::ResourceList
{
public:
	explicit ResourceList(ResourceLayout* layout);
	virtual ~ResourceList(void) override;

public:
	virtual void Update(void) override;

public:
	inline Vulkan::DescriptorSet* GetDescriptorSet(void) const { return mDescriptorSet; }

public:
	static VkDescriptorType GetDescriptorType(Render::ResourceType type);

public:
	static void SetImageInfo(const Render::Resource& resource, VkDescriptorImageInfo* info);
	static void SetUniformInfo(const Render::Resource& resource, VkDescriptorBufferInfo* info);
	static void SetSamplerInfo(const Render::Resource& resource, VkDescriptorImageInfo* info);

protected:
	void WriteDescriptorSet(void);
	void UpdateDescriptorSet(void);

protected:
	Vulkan::DescriptorSet* mDescriptorSet = nullptr;
};

static inline ResourceList* StaticCast(Render::ResourceList* list)
{
	return static_cast<ResourceList*>(list);
}

static inline ResourceList* SaftyCast(Render::ResourceList* list)
{
	return dynamic_cast<ResourceList*>(list);
}

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCELIST_H_ */
