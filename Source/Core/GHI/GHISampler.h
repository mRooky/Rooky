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
#include "../Math/MathColorInt.h"

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
	inline void SetFilterType(FilterType type)
	{
		mFilterType = type;
	}

	inline void SetMipmapMode(MipmapMode mode)
	{
		mMipmapMode = mode;
	}

public:
	inline void SetAddressModeU(AddressMode mode)
	{
		mAddressModeU = mode;
	}

	inline void SetAddressModeV(AddressMode mode)
	{
		mAddressModeV = mode;
	}

	inline void SetAddressModeW(AddressMode mode)
	{
		mAddressModeW = mode;
	}

public:
	inline FilterType GetFilterType(void) const
	{
		return mFilterType;
	}

	inline MipmapMode GetMipmapMode(void) const
	{
		return mMipmapMode;
	}

public:
	inline AddressMode GetAddressModeU(void) const
	{
		return mAddressModeU;
	}

	inline AddressMode GetAddressModeV(void) const
	{
		return mAddressModeV;
	}

	inline AddressMode GetAddressModeW(void) const
	{
		return mAddressModeW;
	}

public:
	inline bool IsValid(void) const
	{
		return mValid;
	}

	inline Math::ColorI GetBorderColor(void) const
	{
		return mBorderColor;
	}

public:
	inline void SetBorderColor(uint32_t color)
	{
		mBorderColor = color;
	}

protected:
	bool mValid = false;
	Math::ColorI mBorderColor = {};

protected:
	FilterType mFilterType = FilterType::LINEAR;
	MipmapMode mMipmapMode = MipmapMode::LINEAR;
	AddressMode mAddressModeU = AddressMode::REPEAT;
	AddressMode mAddressModeV = AddressMode::REPEAT;
	AddressMode mAddressModeW = AddressMode::REPEAT;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERSAMPLER_H_ */
