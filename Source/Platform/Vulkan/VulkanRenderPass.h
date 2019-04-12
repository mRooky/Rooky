/*
 * VulkanRenderPass.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANRENDERPASS_H_
#define VULKAN_VULKANRENDERPASS_H_

#include "VulkanDeviceObject.h"

namespace Vulkan
{
class VULKAN_EXPORT RenderPass: public DeviceObject
{
private:
	explicit RenderPass(Device* device);
	virtual ~RenderPass(void) override;

public:
	VkResult Create(const VkRenderPassCreateInfo* info);

public:
	inline VkRenderPass GetHandle(void) const { return m_pass; }

public:
	static inline RenderPass* New(Device* device) { return new RenderPass(device); }

public:
	static VkRenderPassCreateInfo CreateInfo(void);
	static VkRenderPassBeginInfo BeginInfo(void);

public:
	static VkAttachmentDescription AttachmentDescription(void);
	static VkSubpassDescription SubpassDescription(void);
	static VkSubpassDependency SubpassDenpendency(uint32_t from, uint32_t to);

private:
	VkRenderPass m_pass = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANRENDERPASS_H_ */
