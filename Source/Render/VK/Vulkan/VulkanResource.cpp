/*
 * VulkanResource.cpp
 *
 *  Created on: Aug 22, 2018
 *      Author: rookyma
 */

#include "VulkanResource.h"
#include "VulkanBuffer.h"
#include "VulkanImage.h"
#include "VulkanCommandBuffer.h"

namespace Vulkan
{

Resource::Resource(Device* device):
		DeviceObject(device)
{
}

Resource::~Resource(void)
{
	mMemory = nullptr;
}

} /* namespace Vulkan */
