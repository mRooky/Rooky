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
	virtual void Create(void) override;

public:
	virtual Render::Format GetBestDepthStencilFormat(void) override;

public:
	virtual uint32_t GetImageUsageFlag(uint32_t usage, bool read, bool write) override;

public:
	inline Vulkan::Vendor* GetVendorVK(void) const { return m_vendor; }
	inline Vulkan::Device* GetDeviceVK(void) const { return m_device; }
	inline Vulkan::Instance* GetInstanceVK(void) const { return m_instance; }
	inline Vulkan::PhysicalDevice* GetPhysicalDeviceVK(void) const { return m_physical; }

public:
	inline Vulkan::CommandPool* GetCommandPoolVK(void) const { return m_commandPool; }

private:
	void CreateVendor(void);
	void CreateInstance(bool debug = true);
	void CreatePhysical(void);
	void CreateDevice(void);
	void CreateDefaultPool(void);

private:
	Vulkan::Vendor* m_vendor = nullptr;
	Vulkan::Device* m_device = nullptr;
	Vulkan::Instance* m_instance = nullptr;
	Vulkan::PhysicalDevice* m_physical = nullptr;
	Vulkan::CommandPool* m_commandPool = nullptr;

private:
	std::vector<std::string> m_layers;
	std::vector<std::string> m_extensions;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKCONTEXT_H_ */
