/*
 * DirectWindow.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: rookyma
 */

#include "DirectContext.h"
#include "DirectSurface.h"
#include "DirectWindow.h"
#include "VulkanImage.h"
#include "VulkanDevice.h"
#include "VulkanPhysicalDevice.h"

#include <cassert>

namespace Direct
{
static const VkFormat format = VK_FORMAT_R8G8B8A8_UNORM;
Window::Window(void)
{
}

Window::~Window(void)
{
	DestroySurface();
	Context::Destroy();
	m_context = nullptr;
}

void Window::Create(Vulkan::Device* device, int32_t width, int32_t height)
{
	assert(m_context == nullptr);
	m_width = width;
	m_height = height;
	m_context = Context::New(device);
	CreateSurface(format);
}

void Window::Resize(int32_t width, int32_t height)
{
	if (m_width != width || m_height != height)
	{
		m_width = width;
		m_height = height;
		DestroySurface();
		CreateSurface(format);
	}
}

void Window::CreateSurface(VkFormat format)
{
	assert(m_width != 0 && m_height != 0);
	m_surface = new Surface(this);
	m_surface->Create(m_width, m_height, format);
}

void Window::DestroySurface(void)
{
	delete m_surface;
	m_surface = nullptr;
}

} /* namespace Direct */
