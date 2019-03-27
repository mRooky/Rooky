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
	inline Vulkan::Sampler* GetVulkanSampler(void) const { return mSampler; }

protected:
	Vulkan::Sampler* mSampler = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKSAMPLER_H_ */
