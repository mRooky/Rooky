/*
 * VKImage.h
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKIMAGE_H_
#define SOURCE_RENDER_VK_VKIMAGE_H_

#include "RenderImage.h"
#include "VKRender.h"

namespace VK
{
class Context;
class Image: public Render::Image
{
public:
	explicit Image(Context* context);
	virtual ~Image(void) override;

public:
	virtual void Create(Render::Format format, const Render::Extent3& extent, uint32_t usage) override;
	virtual void Allocate(uint32_t properties) override;
	virtual void CreateView(Render::ImageType type) override;

public:
	virtual void CopyFrom(const Render::Buffer* other) override;

public:
	inline Vulkan::Image* GetImageVK(void) const { return mImage; }
	inline Vulkan::DeviceMemory* GetMemoryVK(void) const { return mMemory; }

public:
	VkDescriptorImageInfo GetDescriptorInfo(void) const;

public:
	static VkImageViewType ConverType(const Render::ImageType& type);
	static Render::ImageType ConverType(const VkImageViewType& type);

protected:
	Vulkan::Image* mImage = nullptr;
	Vulkan::DeviceMemory* mMemory = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKIMAGE_H_ */
