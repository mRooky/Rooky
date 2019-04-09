/*
 * DirectContext.h
 *
 *  Created on: Oct 16, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTCONTEXT_H_
#define DIRECTUI_DIRECTCONTEXT_H_

#include "VulkanClasses.h"
#include <array>

namespace Direct
{

class Context
{
private:
	explicit Context(Vulkan::Device* device);
	virtual ~Context(void);

public:
	inline Vulkan::Instance* GetInstance(void) const { return m_instance; }
	inline Vulkan::PhysicalDevice* GetPhysicalDevice(void) const { return m_physicalDevice; }
	inline Vulkan::Device* GetDevice(void) const { return m_device; }

public:
	static Context* New(Vulkan::Device* device) { return new Context(device); }
	static void Destroy(void) { delete g_context; }

public:
	static Context* GetContext(void) { return g_context; }

private:
	bool m_internal = true;

private:
	Vulkan::Instance* m_instance = nullptr;
	Vulkan::PhysicalDevice* m_physicalDevice = nullptr;
	Vulkan::Device* m_device = nullptr;

private:
	static Context* g_context;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTCONTEXT_H_ */
