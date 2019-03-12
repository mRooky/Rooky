/*
 * ResourceList.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCESTATE_H_
#define SOURCE_RENDER_VK_VKRESOURCESTATE_H_

#include "RenderResourceState.h"
#include "VKRender.h"

namespace VK
{

class ResourceLayout;
class ResourceState : public Render::ResourceState
{
public:
	explicit ResourceState(ResourceLayout* layout);
	virtual ~ResourceState(void) override;

public:
	virtual void Update(void) override;

public:
	inline Vulkan::DescriptorSet* GetDescriptorSet(void) const { return mDescriptorSet; }

public:
	static VkDescriptorType GetDescriptorType(Render::ResourceFlag type);

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

static inline ResourceState* StaticCast(Render::ResourceState* list)
{
	return static_cast<ResourceState*>(list);
}

static inline ResourceState* SaftyCast(Render::ResourceState* list)
{
	return dynamic_cast<ResourceState*>(list);
}

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCESTATE_H_ */
