/*
 * RenderResource.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_GHIBINDING_HPP_
#define SOURCE_CORE_GHI_GHIBINDING_HPP_

#include "GHIEnum.h"
#include <cstddef>
#include <cstdint>

namespace GHI
{

class Resource;
class Binding
{
public:
	Binding(void) = default;
	~Binding(void) = default;

public:
	bool IsValid(void) const
	{
		return (mResource != nullptr && mStage!= ShaderStage::SHADER_STAGE_UNKNOWN);
	}

	inline void SetResource(Resource* resource, ShaderStage stage)
	{
		mStage = stage;
		mResource = resource;
	}

public:
	inline Binding& operator=(const Binding& other)
	{
		mResource = other.mResource;
		mStage = other.mStage;
		return *this;
	}

	inline bool operator==(const Binding& other) const
	{
		return (mResource == other.mResource && mStage == other.mStage);
	}

	inline bool operator!=(const Binding& other) const
	{
		return !(*this == other);
	}

public:
	inline Resource* GetResource(void) const { return mResource; }
	inline ShaderStage GetShaderStage(void) const { return mStage; }

protected:
	Resource* mResource = nullptr;
	ShaderStage mStage = ShaderStage::SHADER_STAGE_UNKNOWN;

};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_GHIBINDING_HPP_ */
