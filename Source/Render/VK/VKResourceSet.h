/*
 * VKResourceSet.h
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRESOURCESET_H_
#define SOURCE_RENDER_VK_VKRESOURCESET_H_

#include "RenderUsage.h"
#include "VKRender.h"
#include <vector>

namespace VK
{
class Image;
class Buffer;
class Sampler;
class ResourceWriter;
class ResourceSet
{
public:
	explicit ResourceSet(ResourceWriter* writer);
	virtual ~ResourceSet(void);

public:
	void UpdateDescriptorSet(void);

public:
	void WriteSamplerImage(VkShaderStageFlagBits stage, uint32_t bind, Image* image, Sampler* sampler);
	void WriteUniformBuffer(VkShaderStageFlagBits stage, uint32_t bind, Buffer* buffer, size_t offset, size_t range);

public:
	VkWriteDescriptorSet* GetWriteSet(size_t bind);
	VkDescriptorSetLayoutBinding* GetLayoutBinding(size_t bind);

public:
	inline Vulkan::DescriptorSet* GetDescriptorSet(void) const { return mDescriptorSet; }

public:
	static void SetDescriptorType(Render::ImageUsage usage, VkWriteDescriptorSet* write);
	static void SetDescriptorType(Render::BufferUsage usage, VkWriteDescriptorSet* write);

protected:
	VkWriteDescriptorSet* AppendOrReplaceInfo(size_t bind, const VkDescriptorImageInfo& info);
	VkWriteDescriptorSet* AppendOrReplaceInfo(size_t bind, const VkDescriptorBufferInfo& info);

protected:
	void AppendOrReplaceBinding(size_t bind, const VkDescriptorSetLayoutBinding& binding);

protected:
	std::vector<VkWriteDescriptorSet> mWrites;
	std::vector<VkDescriptorSetLayoutBinding> mLayoutbindings;

protected:
	bool mDirty = true;
	ResourceWriter* mWriter = nullptr;
	Vulkan::DescriptorSet* mDescriptorSet = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRESOURCESET_H_ */
