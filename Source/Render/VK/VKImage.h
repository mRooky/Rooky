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
	virtual void Initialize(Render::Format format, uint32_t width, uint32_t height, uint32_t usage) override;
	virtual void BindMemory(Render::Memory* memory, size_t offset) override;
	virtual void CreateView(void) override;

public:
	inline Vulkan::Image* GetImageVK(void) const { return mImage; }

public:
	VkDescriptorImageInfo GetDescriptorInfo(void) const;

protected:
	Vulkan::Image* mImage = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKIMAGE_H_ */
