/*
 * VulkanCommandBuffer.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANCOMMANDBUFFER_H_
#define VULKAN_VULKANCOMMANDBUFFER_H_

#include "VulkanClasses.h"
#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class VULKAN_EXPORT CommandBuffer: public DeviceObject
{
	friend class CommandPool;
private:
	explicit CommandBuffer(Device* device);
	virtual ~CommandBuffer(void) override;

private:
	VkResult Create(CommandPool* pool, VkCommandBufferLevel level);

public:
	void Begin(VkCommandBufferUsageFlags flags);
	void BeginRenderPass(const VkRenderPassBeginInfo& info);
	void BeginRenderPass(RenderPass* pass, FrameBuffer* frame, VkRect2D area);
	void BindPipeline(Pipeline* pipeline);
	void PushConstants(PipelineLayout* layout, uint32_t offset, uint32_t size, const void* data);
	void BindDescriptorSets(PipelineLayout* layout, const std::vector<DescriptorSet*>& sets, const std::vector<uint32_t>& offsets);
	void BindVertexBuffers(Buffer* buffer, uint32_t binding, VkDeviceSize offset);
	void BindIndexBuffer(Buffer* buffer, VkDeviceSize offset, VkIndexType type);
	void SetScissor(uint32_t first, uint32_t count, const VkRect2D* scissors);
	void SetViewport(uint32_t first, uint32_t count, const VkViewport* viewports);
	void Draw(DrawCall* draw);
	void EndRenderPass(void);
	void End(void);

public:
	void ClearAttachments(const VkClearAttachment* attachment, const VkClearRect* rect);
	void ClearAttachments(const std::vector<VkClearAttachment>& attachments, const std::vector<VkClearRect>& rects);

public:
	void CopyResource(Buffer* source, Buffer* dest, std::vector<VkBufferCopy>& regions);
	void CopyResource(Image* source, Buffer* dest, std::vector<VkBufferImageCopy>& regions);
	void CopyResource(Buffer* source, Image* dest, std::vector<VkBufferImageCopy>& regions);
	void CopyResource(Image* source, Image* dest, std::vector<VkImageCopy>& regions);

public:
	void CopyResource(Buffer* source, Buffer* dest, size_t count, const VkBufferCopy* regions);
	void CopyResource(Image* source, Buffer* dest, size_t count, const VkBufferImageCopy* regions);
	void CopyResource(Buffer* source, Image* dest, size_t count, const VkBufferImageCopy* regions);
	void CopyResource(Image* source, Image* dest, size_t count, const VkImageCopy* regions);

public:
	inline bool IsBegin(void) const { return m_begin; }

public:
	inline VkCommandBuffer GetHandle(void) const { return m_buffer; }
	inline Semaphore* GetSemaphore(void) const { return m_semaphore; }

public:
	static inline CommandBuffer* New(Device* device) { return new CommandBuffer(device); }

public:
	static VkCommandBufferAllocateInfo AllocateInfo(void);
	static VkCommandBufferBeginInfo BeginInfo(void);

protected:
	virtual void Destroy(void) override { Object::Destroy(); }

private:
	VkResult Create(const VkCommandBufferAllocateInfo* info);

private:
	bool m_begin = false;

private:
	CommandPool* m_pool = nullptr;
	Semaphore* m_semaphore = nullptr;
	VkCommandBuffer m_buffer = VK_NULL_HANDLE;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANCOMMANDBUFFER_H_ */
