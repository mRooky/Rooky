/*
 * Sampler.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSAMPLER_H_
#define SOURCE_CORE_RENDER_RENDERSAMPLER_H_

#include "RenderResource.h"
#include "RenderSamplerState.h"
#include "RenderColor.hpp"

namespace Render
{

class Sampler: public Resource
{
public:
	explicit Sampler(Device* device);
	virtual ~Sampler(void) override;

public:
	virtual void Create(void) = 0;

public:
	inline bool IsValid(void) const { return mValid; }
	inline Color GetBorderColor(void) const { return mBorderColor; }

public:
	inline void SetBorderColor(uint32_t color) { mBorderColor.Set(color); }

protected:
	bool mValid = false;
	Color mBorderColor = {};

protected:
	FilterType mFilterType = FilterType::FILTER_TYPE_LINEAR;
	MipmapMode mMipmapMode = MipmapMode::MIPMAP_MODE_LINEAR;
	AddressMode mAddressMode = AddressMode::ADDRESS_MODE_REPEAT;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSAMPLER_H_ */
