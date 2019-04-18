/*
 * VKContext.h
 *
 *  Created on: Jan 22, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKDEVICE_H_
#define SOURCE_RENDER_VK_VKDEVICE_H_

#include "RenderDevice.h"
#include "VKRender.h"
#include <string>
#include <vector>

namespace VK
{

class Device : public Render::Device
{
public:
	Device(void);
	virtual ~Device(void) override;

public:
	virtual void Create(void) override;

public:
	virtual Render::Format GetBestDepthStencilFormat(void) override;

public:
	inline Vulkan::Vendor* GetVulkanVendor(void) const { return m_vendor; }
	inline Vulkan::Device* GetVulkanDevice(void) const { return m_device; }
	inline Vulkan::Instance* GetVulkanInstance(void) const { return m_instance; }
	inline Vulkan::PhysicalDevice* GetVulkanPhysicalDevice(void) const { return m_physical; }

private:
	void CreateVendor(void);
	void CreateInstance(bool debug = true);
	void CreatePhysical(void);
	void CreateDevice(void);
	void CreateQueue(size_t count);

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

#endif /* SOURCE_RENDER_VK_VKDEVICE_H_ */
