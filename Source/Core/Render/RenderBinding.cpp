/*
 * RenderResource.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "RenderBinding.h"
#include <cassert>

namespace Render
{

Binding::Binding(void)
{
}

Binding::~Binding(void)
{
}

bool Binding::IsValid(void) const
{
	bool valid = mResource != nullptr;
	valid = valid && mStage!= ShaderStage::SHADER_STAGE_UNKNOWN;
	valid = valid && mType != ResourceFlag::RESOURCE_TYPE_COMMON;
	return valid;
}

Binding& Binding::operator=(const Binding& other)
{
	mType = other.mType;
	mResource = other.mResource;
	mStage = other.mStage;
	return *this;
}

void Binding::SetResource(Resource* resource, ShaderStage stage)
{
	mResource = resource;
	mStage = stage;
	mType = ResourceFlag::RESOURCE_TYPE_IMAGE;
}

} /* namespace Render */
