/*
 * RenderBinding.cpp
 *
 *  Created on: Feb 28, 2019
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
	mResource = nullptr;
	mStage = ShaderStage::SHADER_STAGE_UNKNOWN;
	mType = ResourceType::RESOURCE_TYPE_COMMON;
}

bool Binding::IsValid(void) const
{
	bool valid = mResource != nullptr;
	valid = valid && mStage!= ShaderStage::SHADER_STAGE_UNKNOWN;
	valid = valid && mType != ResourceType::RESOURCE_TYPE_COMMON;
	return valid;
}

Binding& Binding::operator=(const Binding& other)
{
	mType = other.mType;
	mResource = other.mResource;
	mStage = other.mStage;
	return *this;
}

} /* namespace Render */
