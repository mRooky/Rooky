/*
 * VKSampler.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKSAMPLER_H_
#define SOURCE_RENDER_VK_VKSAMPLER_H_

#include "RenderSampler.h"
#include "VKRender.h"

namespace VK
{
class Device;
class Sampler: public Render::Sampler
{
public:
	explicit Sampler(Device* device);
	virtual ~Sampler(void) override;

public:
	virtual void Create(void) override;

public:
	inline Vulkan::Sampler* GetVulkanSampler(void) const { return mSampler; }

public:
	static VkFilter GetFilter(Render::FilterType type);
	static VkSamplerMipmapMode GetMipmapMode(Render::MipmapMode mode);
	static VkSamplerAddressMode GetAddressMode(Render::AddressMode mode);

protected:
	Vulkan::Sampler* mSampler = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKSAMPLER_H_ */
