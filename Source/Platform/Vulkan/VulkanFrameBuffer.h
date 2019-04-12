/*
 * VulkanFrameBuffer.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANFRAMEBUFFER_H_
#define VULKAN_VULKANFRAMEBUFFER_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class Image;
class Device;
class RenderPass;
class VULKAN_EXPORT FrameBuffer: public DeviceObject
{
private:
	explicit FrameBuffer(Device* device);
	virtual ~FrameBuffer(void) override;

public:
	VkResult Create(RenderPass* parent, const std::vector<Image*>& attachments, VkExtent2D extent);

public:
	inline VkFramebuffer GetHandle(void) const { return m_frameBuffer; }
	inline RenderPass* GetParent(void) const { return m_parent; }

public:
	inline size_t GetAttachmentCount(void) const { return mAttachments.size(); }
	inline Image* GetAttachment(uint32_t index) const { return mAttachments.at(index); }

public:
	static inline FrameBuffer* New(Device* device) { return new FrameBuffer(device); }

public:
	static VkFramebufferCreateInfo CreateInfo(void);

public:
	VkResult Create(const VkFramebufferCreateInfo* info);

private:
	RenderPass* m_parent = nullptr;
	std::vector<Image*> mAttachments;
	VkFramebuffer m_frameBuffer = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANFRAMEBUFFER_H_ */
