/*
 * RenderBinding.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBINDING_H_
#define SOURCE_CORE_RENDER_RENDERBINDING_H_

#include "RenderEnum.h"
#include <cstdint>

namespace Render
{

enum class ResourceType : uint32_t
{
	RESOURCE_TYPE_COMMON,
	RESOURCE_TYPE_BUFFER,
	RESOURCE_TYPE_TEXTURE,
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
	inline void SetResource(Resource* resource) { mResource = resource; }
	inline void SetShaderStage(ShaderStage stage) { mStage = stage; }
	inline void SetResourceType(ResourceType type) { mType = type; }

public:
	inline bool operator==(const Binding& other)
	{
		return mType == other.mType && mResource == other.mResource && mStage == other.mStage;
	}

	inline bool operator!=(const Binding& other) { return !(*this == other); }

public:
	inline Resource* GetResource(void) const { return mResource; }
	inline ShaderStage GetShaderStage(void) const { return mStage; }
	inline ResourceType GetResourceType(void) const { return mType; }

protected:
	Resource* mResource = nullptr;
	ShaderStage mStage = ShaderStage::SHADER_STAGE_UNKNOWN;
	ResourceType mType = ResourceType::RESOURCE_TYPE_COMMON;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBINDING_H_ */
