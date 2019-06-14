/*
 * Sampler.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERSAMPLER_H_
#define SOURCE_CORE_GHI_RENDERSAMPLER_H_

#include "GHIResource.h"
#include "GHISamplerState.h"


#include "../Math/MathColor.h"

namespace GHI
{

class Sampler: public Resource
{
public:
	explicit Sampler(Device* device);
	virtual ~Sampler(void) override;

public:
	virtual void Create(void) = 0;

public:
	inline void SetFilterType(FilterType type) { mFilterType = type; }
	inline void SetMipmapMode(MipmapMode mode) { mMipmapMode = mode; }
	inline void SetAddressMode(AddressMode mode) { mAddressMode = mode; }

public:
	inline FilterType GetFilterType(void) const { return mFilterType; }
	inline MipmapMode GetMipmapMode(void) const { return mMipmapMode; }
	inline AddressMode GetAddressMode(void) const { return mAddressMode; }

public:
	inline bool IsValid(void) const { return mValid; }
	inline Math::Color GetBorderColor(void) const { return mBorderColor; }

public:
	inline void SetBorderColor(uint32_t color) { mBorderColor.Set(color); }

protected:
	bool mValid = false;
	Math::Color mBorderColor = {};

protected:
	FilterType mFilterType = FilterType::LINEAR;
	MipmapMode mMipmapMode = MipmapMode::LINEAR;
	AddressMode mAddressMode = AddressMode::REPEAT;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERSAMPLER_H_ */
