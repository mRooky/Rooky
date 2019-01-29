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
class Context;
class Sampler: public Render::Sampler
{
public:
	explicit Sampler(Context* context);
	virtual ~Sampler(void) override;

public:
	inline Vulkan::Sampler* GetSamplerVK(void) const { return mSampler; }

protected:
	Vulkan::Sampler* mSampler = nullptr;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKSAMPLER_H_ */
