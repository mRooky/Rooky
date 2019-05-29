/*
 * DirectSurface.cpp
 *
 *  Created on: Oct 16, 2018
 *      Author: rookyma
 */

#include "DirectContext.h"
#include "DirectPainter.h"
#include "DirectSurface.h"
#include "DirectTarget.h"
#include "DirectWidget.h"
#include "DirectWindow.h"
#include "../Platform/Vulkan/VulkanImage.h"
#include "../Platform/Vulkan/VulkanDevice.h"
#include "../Platform/Vulkan/VulkanRenderPass.h"
#include "../Platform/Vulkan/VulkanCommandPool.h"
#include "../Platform/Vulkan/VulkanFrameBuffer.h"
#include "../Platform/Vulkan/VulkanCommandBuffer.h"
#include "../Platform/Vulkan/VulkanPhysicalDevice.h"
#include "../Platform/Vulkan/VulkanInline.h"
#include <cassert>

namespace Direct
{
Surface::Surface(Window* parent)
{
	assert(parent != nullptr);
	m_parent = parent;
	m_painters.clear();
	m_copyRegions.clear();
}

Surface::~Surface(void)
{
	for (auto painter : m_painters)
	{
		delete painter;
	}
	m_painters.clear();
	delete m_backend;
	delete m_frontend;
	m_copyRegions.clear();
	m_commandBuffer = nullptr;
	Vulkan::Release(m_renderPass);
	Vulkan::Release(m_frameBuffer);
	Vulkan::Release(m_commandPool);
}

void Surface::Create(uint32_t width, uint32_t height, VkFormat format)
{
	m_width = width;
	m_height = height;
	CreateTarget(format);
	CreateCommandPool();
	CreateCommandBuffer();
	CreateRenderPass();
	CreateFrameBuffer();
}

void Surface::CreateTarget(VkFormat format)
{
	m_frontend = new Target;
	m_frontend->CreateImage(m_width, m_height, format);
	m_frontend->CreateMemory(VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
	m_frontend->BindingMemory(nullptr);

	m_backend = new Target;
	m_backend->CreateImage(m_width, m_height, format);
	m_backend->CreateMemory(VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
	m_backend->BindingMemory(nullptr);
}

void Surface::CreateCommandPool(void)
{
	auto device = Context::GetContext()->GetDevice();
	auto physical = device->GetPhysicalDevice();
	uint32_t family = physical->GetFamily();
	m_commandPool = Vulkan::CommandPool::New(device);
	m_commandPool->Create(family);
}

void Surface::CreateCommandBuffer(void)
{
	assert(m_commandPool != nullptr);
	m_commandBuffer = m_commandPool->Allocate(VK_COMMAND_BUFFER_LEVEL_PRIMARY);
}

void Surface::CreateRenderPass(void)
{
	VkFormat format = m_frontend->GetFormat();
	VkAttachmentDescription description = Vulkan::Image::GetDescription(format);
	VkAttachmentReference reference = Vulkan::Image::GetReference(format);

	VkSubpassDescription subpass_description = {};
	subpass_description.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
	subpass_description.colorAttachmentCount = 1;
	subpass_description.pColorAttachments = &reference;

	std::vector<VkSubpassDependency> subpass_dependencies;
	subpass_dependencies.push_back(Vulkan::RenderPass::SubpassDenpendency(VK_SUBPASS_EXTERNAL, 0));
	subpass_dependencies.push_back(Vulkan::RenderPass::SubpassDenpendency(0, VK_SUBPASS_EXTERNAL));

	VkRenderPassCreateInfo renderpass_create_info = Vulkan::RenderPass::CreateInfo();
	renderpass_create_info.attachmentCount = 1;
	renderpass_create_info.pAttachments = &description;
	renderpass_create_info.subpassCount = 1;
	renderpass_create_info.pSubpasses = &subpass_description;
	renderpass_create_info.dependencyCount = subpass_dependencies.size();
	renderpass_create_info.pDependencies = subpass_dependencies.data();

	Vulkan::Device* device = Context::GetContext()->GetDevice();
	m_renderPass = Vulkan::RenderPass::New(device);
	m_renderPass->Create(&renderpass_create_info);
}

void Surface::CreateFrameBuffer(void)
{
	assert(m_backend != nullptr);
	assert(m_renderPass != nullptr);
	Vulkan::Image* attachment = m_backend->GetImage();
	std::vector<Vulkan::Image*> attachments = { attachment };
	VkExtent2D extent = { static_cast<uint32_t>(m_width), static_cast<uint32_t>(m_height) };

	Vulkan::Device* device = Context::GetContext()->GetDevice();
	m_frameBuffer = Vulkan::FrameBuffer::New(device);
	m_frameBuffer->Create(m_renderPass, attachments, extent);
}

void Surface::BeginFrame(void)
{
	assert(m_commandBuffer != nullptr);
	assert(!m_commandBuffer->IsBegin());
	m_commandBuffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
	m_copyRegions.clear();
}

void Surface::Draw(Widget* widget)
{
	assert(m_commandBuffer != nullptr);
	assert(m_commandBuffer->IsBegin());
	VkImageCopy image_copy = widget->GetCopyRegion();
	m_copyRegions.push_back(image_copy);
	widget->Draw(this);
}

void Surface::EndFrame(void)
{
	assert(m_commandBuffer != nullptr);
	assert(m_commandBuffer->IsBegin());
	m_commandBuffer->End();
	CopyTargets();
}

void Surface::CopyTargets(void)
{
	if (m_copyRegions.size() > 0)
	{
		assert(m_commandBuffer != nullptr);
		assert(!m_commandBuffer->IsBegin());
		Vulkan::Image* resource = m_backend->GetImage();
		Vulkan::Image* destnation = m_backend->GetImage();
		m_commandBuffer->Begin(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
		m_commandBuffer->CopyResource(resource, destnation, m_copyRegions);
	}
}

Painter* Surface::CreatePainter(void)
{
	Painter* painter = new Painter(this);
	m_painters.push_back(painter);
	return painter;
}

} /* namespace Direct */
