/*
 * ResourceList.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCELIST_H_
#define SOURCE_RENDER_VK_VKRESOURCELIST_H_

#include "RenderResource.h"
#include "VKRender.h"

#include <map>
#include <vector>

namespace VK
{

enum class DirtyState : uint32_t
{
	DIRTY_STATE_NONE,
	DIRTY_STATE_LAYOUT,
	DIRTY_STATE_RESOURCE,
	DIRTY_STATE_UNKNOWN = ~0U
};

class ResourceLayout;
class ResourceList
{
public:
	explicit ResourceList(ResourceLayout* layout);
	virtual ~ResourceList(void);

public:
	void SetBinding(uint32_t bind, const Render::Resource& resource);

public:
	DirtyState Update(void);

public:
	inline bool IsDirty(void) const { return mDirty; }
	inline Vulkan::DescriptorSet* GetDescriptorSet(void) const { return mDescriptorSet; }

public:
	static VkDescriptorType GetDescriptorType(Render::ResourceType type);

public:
	static void SetImageInfo(const Render::Resource& resource, VkDescriptorImageInfo* info);
	static void SetUniformInfo(const Render::Resource& resource, VkDescriptorBufferInfo* info);

protected:
	void WriteDescriptorSet(void);
	DirtyState UpdateDescriptorSet(void);

protected:
	bool mDirty = true;
	ResourceLayout* mLayout = nullptr;
	std::map<uint32_t, Render::Resource> mResources;

protected:
	Vulkan::DescriptorSet* mDescriptorSet = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCELIST_H_ */
