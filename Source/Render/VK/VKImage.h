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
	virtual void Initialize(Render::Format format, const Render::Extent3& extent, uint32_t usage) override;
	virtual void AllocateMemory(uint32_t properties) override;
	virtual void CreateView(Render::Image::Type type) override;

public:
	inline Vulkan::Image* GetImageVK(void) const { return mImage; }

public:
	VkDescriptorImageInfo GetDescriptorInfo(void) const;

public:
	static VkImageViewType ConverType(const Render::Image::Type& type);
	static Render::Image::Type ConverType(const VkImageViewType& type);

protected:
	Vulkan::Image* mImage = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKIMAGE_H_ */
