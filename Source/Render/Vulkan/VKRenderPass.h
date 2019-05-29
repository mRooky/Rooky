/*
 * VKRenderPass.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKRENDERPASS_H_
#define SOURCE_RENDER_VK_VKRENDERPASS_H_

#include "VKRender.h"
#include "../../Core/GHI/GHIRenderPass.h"

namespace VK
{
class Device;
class RenderPass: public GHI::RenderPass
{
public:
	explicit RenderPass(Device* device);
	virtual ~RenderPass(void) override;

public:
	virtual void Create(size_t count) override;

public:
	virtual GHI::FrameBuffer* CreateFrameBuffer(void) override;

public:
	inline Vulkan::RenderPass* GetVulkanRenderPass(void) const { return mRenderPass; }
	inline const VkRenderPassCreateInfo& GetCreateInfo(void) const { return mRenderpassCreateInfo; }

protected:
	void CreateReference(void);
	void CreateDescription(void);
	void CreateSubDependency(size_t count);
	void CreateSubDescription(size_t count);

protected:
	Vulkan::RenderPass* mRenderPass = nullptr;

protected:
	VkAttachmentReference mDepthReference = {};
	VkRenderPassCreateInfo mRenderpassCreateInfo = {};
	std::vector<VkAttachmentReference> mReferences;
	std::vector<VkAttachmentDescription> mDescriptions;
	std::vector<VkSubpassDependency> mSubDependencies;
	std::vector<VkSubpassDescription> mSubDescriptions;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKRENDERPASS_H_ */
