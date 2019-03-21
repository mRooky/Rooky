/*
 * RenderResource.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBINDING_H_
#define SOURCE_CORE_RENDER_RENDERBINDING_H_

#include "RenderEnum.h"
#include <cstddef>
#include <cstdint>

namespace Render
{

enum class ResourceFlag : uint32_t
{
	RESOURCE_TYPE_COMMON,
	RESOURCE_TYPE_IMAGE,
	RESOURCE_TYPE_BUFFER,
	RESOURCE_TYPE_UNIFORM,
	RESOURCE_TYPE_SAMPLER,
	RESOURCE_TYPE_TARGET,
	RESOURCE_TYPE_UNKNOWN = ~0U
};

class Resource;
class Binding
{
public:
	Binding(void);
	virtual ~Binding(void);

public:
	bool IsValid(void) const;
	Binding& operator=(const Binding& other);

public:
	inline bool operator==(const Binding& other) const
	{
		return mType == other.mType && mResource == other.mResource && mStage == other.mStage;
	}
	inline bool operator!=(const Binding& other) const { return !(*this == other); }

public:
	void SetResource(Resource* resource, ShaderStage stage);

public:
	inline Resource* GetResource(void) const { return mResource; }
	inline ShaderStage GetShaderStage(void) const { return mStage; }
	inline ResourceFlag GetResourceType(void) const { return mType; }

protected:
	Resource* mResource = nullptr;
	ShaderStage mStage = ShaderStage::SHADER_STAGE_UNKNOWN;
	ResourceFlag mType = ResourceFlag::RESOURCE_TYPE_COMMON;

};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBINDING_H_ */
