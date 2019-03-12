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
	virtual void Create(const Render::ImageLayout& layout) override;
	virtual void CreateView(Render::ImageType type) override;

public:
	virtual void* Map(size_t offset, size_t size) override;
	virtual void Unmap(size_t offset, size_t size) override;

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

public:
	static VkImageUsageFlags ConvertUsageFlag(Render::ResourceUsage usage);

private:
	void CreateImage(void);
	void AllocateMemory(void);

protected:
	Vulkan::Image* mImage = nullptr;
	Vulkan::DeviceMemory* mMemory = nullptr;
};

static inline Image* StaticCast(Render::Image* image)
{
	return static_cast<Image*>(image);
}

static inline Image* SaftyCast(Render::Image* image)
{
	return dynamic_cast<Image*>(image);
}

class SwapChainImage final : private Image
{
	friend class SwapChain;
private:
	explicit SwapChainImage(Context* context);
	virtual ~SwapChainImage(void) override;

private:
	virtual void Create(Vulkan::Image* image);
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKIMAGE_H_ */
