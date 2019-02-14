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

#include <cassert>

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
	virtual void Allocate(bool mappable) override;
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
	static VkImageUsageFlags ConvertUsageFlag(uint32_t usage);

protected:
	Vulkan::Image* mImage = nullptr;
	Vulkan::DeviceMemory* mMemory = nullptr;
};

class SwapChainImage final : public Image
{
	friend class SwapChain;
private:
	explicit SwapChainImage(Context* context);
	virtual ~SwapChainImage(void) override;

private:
	virtual void Create(Vulkan::Image* image);

public:
	virtual void Create(Render::Format format, const Render::Extent3& extent, uint32_t usage) override { assert(false); }
	virtual void Allocate(bool mappable) override { assert(false); }
	virtual void CreateView(Render::ImageType type) override { assert(false); }
	virtual void* Map(size_t offset, size_t size) override { assert(false); return nullptr; }
	virtual void Unmap(size_t offset, size_t size) override { assert(false); }
	virtual void CopyFrom(const Render::Buffer* other) override { assert(false); }
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKIMAGE_H_ */
