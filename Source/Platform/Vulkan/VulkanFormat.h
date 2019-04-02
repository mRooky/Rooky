/*
 * VulkanFormat.h
 *
 *  Created on: Aug 30, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANFORMAT_H_
#define VULKAN_VULKANFORMAT_H_

#include <vulkan/vulkan.h>

namespace Vulkan
{

class Format
{
public:
	static size_t GetFormatSize(VkFormat format);
	static const char* GetFormatString(VkFormat format);

private:
	Format(void) = delete;
	~Format(void) = delete;
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANFORMAT_H_ */
