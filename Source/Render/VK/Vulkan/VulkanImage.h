/*
 * VulkanImage.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANIMAGE_H_
#define VULKAN_VULKANIMAGE_H_

#include "VulkanResource.h"

namespace Vulkan
{
class ImageView;
class CommandBuffer;
class ROOKY_EXPORT Image: public Resource
{
protected:
	explicit Image(Device* device);
	virtual ~Image(void) override;

public:
	VkResult Create(VkFormat format, const VkExtent3D& extent, VkImageUsageFlags usage);
	VkResult Create(VkFormat format, const VkExtent3D& extent, uint32_t mipmap, uint32_t array, VkImageUsageFlags usage);

public:
	VkResult CreateView(VkImageViewType type);

public:
	VkClearValue GetClearValue(void) const;

public:
	virtual VkResult BindMemory(DeviceMemory* memory, VkDeviceSize offset) override;

public:
	inline VkImage GetHandle(void) const { return mImage; }
	inline ImageView* GetView(void) const { return m_view; }
	inline VkFormat GetFormat(void) const { return mInfo.format; }
	inline VkImageLayout GetLayout(void) const { return mInfo.initialLayout; }
	inline const VkImageCreateInfo& GetInfo(void) const { return mInfo; }

public:
	VkExtent2D GetExtent(void) const;

public:
	VkImageLayout SetLayout(CommandBuffer* command, VkImageLayout layout);
	void ClearValue(CommandBuffer* command, VkClearValue value, uint32_t count, const VkImageSubresourceRange* ranges);

public:
	static inline Image* New(Device* device) { return new Image(device); }

public:
	VkDescriptorImageInfo GetDescriptorInfo(void) const;
	VkImageMemoryBarrier GetMemoryBarrier(void) const;

public:
	static VkAttachmentDescription GetDescription(VkFormat format);
	static VkAttachmentReference GetReference(VkFormat format);
	static VkImageMemoryBarrier MemoryBarrier(void);
	static VkAccessFlags GetAccessFlags(VkImageLayout layout);
	static VkPipelineStageFlags GetStageFlags(VkImageLayout layout);

public:
	static VkImageCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkImageCreateInfo* info);

protected:
	VkImage mImage = VK_NULL_HANDLE;
	VkImageCreateInfo mInfo = {};

private:
	ImageView* m_view = nullptr;
};

class ROOKY_EXPORT SwapChainImage : public Image
{
	friend class SwapChain;
private:
	explicit SwapChainImage(Device* device);
	virtual ~SwapChainImage(void) override;

public:
	static inline SwapChainImage* New(Device* device) { return new SwapChainImage(device); }

private:
	VkResult Create(VkImage image, const VkImageCreateInfo* info);
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANIMAGE_H_ */
