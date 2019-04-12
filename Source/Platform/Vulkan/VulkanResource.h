/*
 * VulkanResource.h
 *
 *  Created on: Aug 22, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANRESOURCE_H_
#define VULKAN_VULKANRESOURCE_H_

#include "VulkanDeviceObject.h"
#include <vector>

namespace Vulkan
{
class DeviceMemory;
class VULKAN_EXPORT Resource : public DeviceObject
{
public:
	explicit Resource(Device* device);
	virtual ~Resource(void) override;

public:
	virtual VkResult BindMemory(DeviceMemory* memory, VkDeviceSize offset) = 0;

public:
	inline DeviceMemory* GetBindMemory(void) const { return mMemory; }
	inline VkDeviceSize GetBindOffset(void) const { return mOffset; }
	inline const VkMemoryRequirements& GetMemoryRequirements(void) const { return mRequirement; }

protected:
	VkDeviceSize mOffset = 0;
	DeviceMemory* mMemory = nullptr;

protected:
	VkMemoryRequirements mRequirement = {};
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANRESOURCE_H_ */
