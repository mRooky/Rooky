/*
 * VulkanSampler.h
 *
 *  Created on: Aug 18, 2018
 *      Author: rookyma
 */

#ifndef VULKAN_VULKANSAMPLER_H_
#define VULKAN_VULKANSAMPLER_H_

#include "VulkanDeviceObject.h"

namespace Vulkan
{
class ROOKY_EXPORT Sampler: public DeviceObject
{
private:
	explicit Sampler(Device* device);
	virtual ~Sampler(void) override;

public:
	VkResult Create(VkFilter filter, VkSamplerAddressMode address, VkSamplerMipmapMode mipmap);

public:
	inline VkSampler GetHandle(void) const { return m_sampler; }
	inline const VkSamplerCreateInfo& GetInfo(void) const { return m_info; }

public:
	VkDescriptorImageInfo GetDescriptorInfo(void) const;

public:
	static inline Sampler* New(Device* device) { return new Sampler(device); }

public:
	static VkSamplerCreateInfo CreateInfo(void);

private:
	VkResult Create(const VkSamplerCreateInfo* info);

private:
	VkSampler m_sampler = VK_NULL_HANDLE;
	VkSamplerCreateInfo m_info = {};
};

} /* namespace Vulkan */

#endif /* VULKAN_VULKANSAMPLER_H_ */
