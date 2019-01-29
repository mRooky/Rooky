/*
 * VKContext.h
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKCONTEXT_H_
#define SOURCE_RENDER_VK_VKCONTEXT_H_

#include "RenderContext.h"
#include "VKRender.h"
#include <string>
#include <vector>

namespace VK
{

class Context : public Render::Context
{
public:
	Context(void);
	virtual ~Context(void) override;

public:
	void Create(VkQueueFlags flags, bool debug);

public:
	Vulkan::Vendor* GetVendorVK(void) const { return m_vendor; }
	Vulkan::Device* GetDeviceVK(void) const { return m_device; }
	Vulkan::Instance* GetInstanceVK(void) const { return m_instance; }
	Vulkan::PhysicalDevice* GetPhysicalDeviceVK(void) const { return m_physical; }

private:
	void CreateVendor(void);
	void CreateInstance(bool debug);
	void CreatePhysical(VkQueueFlags flags);
	void CreateDevice(void);


private:
	Vulkan::Vendor* m_vendor = nullptr;
	Vulkan::Device* m_device = nullptr;
	Vulkan::Instance* m_instance = nullptr;
	Vulkan::PhysicalDevice* m_physical = nullptr;

private:
	std::vector<std::string> m_layers;
	std::vector<std::string> m_extensions;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKCONTEXT_H_ */
