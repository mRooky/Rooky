/*
 * VulkanDeviceObject.h
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANDEVICEOBJECT_H_
#define VULKAN_VULKANDEVICEOBJECT_H_

#include "VulkanObject.h"

namespace Vulkan
{
class Device;
class VULKAN_EXPORT DeviceObject: public Object
{
protected:
	explicit DeviceObject(Device* device);
	virtual ~DeviceObject(void) override;

public:
	inline Device* GetDevice(void) const { return mDevice; }

protected:
	Device* mDevice = nullptr;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANDEVICEOBJECT_H_ */
