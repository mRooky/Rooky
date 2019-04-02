/*
 * VulkanDeviceObject.cpp
 *
 *  Created on: Aug 14, 2018
 *      Author: rookyma
 */

#include "VulkanDeviceObject.h"
#include <cassert>

namespace Vulkan
{

DeviceObject::DeviceObject(Device* device):
		mDevice(device)
{
	assert(mDevice != nullptr);
}

DeviceObject::~DeviceObject(void)
{
	mDevice = nullptr;
}

} /* namespace Vulkan */
