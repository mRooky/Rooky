/*
 * VulkanImageView.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANIMAGEVIEW_H_
#define VULKAN_VULKANIMAGEVIEW_H_

#include "VulkanDeviceObject.h"

namespace Vulkan
{
class Image;
class ROOKY_EXPORT ImageView: public DeviceObject
{
private:
	explicit ImageView(Device* device);
	virtual ~ImageView(void) override;

public:
	VkResult Create(Image* image, VkImageViewType type, VkImageSubresourceRange range);

public:
	inline VkImageView GetHandle(void) const { return m_view; }

public:
	static inline ImageView* New(Device* device) { return new ImageView(device); }

public:
	static bool IsDepthFormat(VkFormat format);
	static VkImageAspectFlags GetAspectFlags(VkFormat format);

public:
	static VkImageViewCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkImageViewCreateInfo* info);

private:
	Image* m_image = nullptr;
	VkImageView m_view = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANIMAGEVIEW_H_ */
