/*
 * VKImage.h
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKIMAGE_H_
#define SOURCE_RENDER_VK_VKIMAGE_H_

#include "VKRender.h"
#include "../../Core/GHI/GHIImage.h"

namespace VK
{
class Device;
class Image: public GHI::Image
{
public:
	explicit Image(Device* device);
	virtual ~Image(void) override;

public:
	virtual void Create(const GHI::ImageLayout& layout, const GHI::ResourceUsage& usage) override;

public:
	virtual void Download(void* dst) override;
	virtual void Upload(uint32_t index, uint32_t mipmap, const void* src) override;

public:
	virtual void* Map(size_t offset, size_t size) override;
	virtual void Unmap(size_t offset, size_t size) override;

public:
	virtual void CopyFrom(const GHI::Resource* other) override;

public:
	inline Vulkan::Image* GetVulkanImage(void) const { return mImage; }
	inline Vulkan::DeviceMemory* GetVulkanMemory(void) const { return mMemory; }

public:
	VkClearValue GetClearValue(void) const;
	VkDescriptorImageInfo GetDescriptorInfo(void) const;

public:
	VkImageUsageFlags ConvertUsageFlag(void);
	VkDescriptorType GetDescriptorType(void);

public:
	static VkImageViewType ConverType(const GHI::ImageType& type);
	static GHI::ImageType ConverType(const VkImageViewType& type);

protected:
	void CreateImage(void);
	void CreateView(void);
	void AllocateMemory(void);

protected:
	size_t GetMipmapSize(uint32_t mipmap) const;
	VkExtent2D GetMipmapExtent(uint32_t mipmap) const;

protected:
	Vulkan::Image* mImage = nullptr;
	Vulkan::DeviceMemory* mMemory = nullptr;
};

class SwapChainImage final : private Image
{
	friend class SwapChain;
private:
	explicit SwapChainImage(Device* device);
	virtual ~SwapChainImage(void) override;

private:
	virtual void Create(Vulkan::Image* image);
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKIMAGE_H_ */
