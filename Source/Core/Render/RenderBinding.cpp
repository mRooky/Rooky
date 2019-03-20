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
	bool valid = mObject != nullptr;
	valid = valid && mStage!= ShaderStage::SHADER_STAGE_UNKNOWN;
	valid = valid && mType != ResourceFlag::RESOURCE_TYPE_COMMON;
	return valid;
}

Binding& Binding::operator=(const Binding& other)
{
	mType = other.mType;
	mObject = other.mObject;
	mStage = other.mStage;
	return *this;
}

void Binding::SetImage(Image* image, ShaderStage stage)
{
	mImage = image;
	mStage = stage;
	mType = ResourceFlag::RESOURCE_TYPE_IMAGE;
}

void Binding::SetUniform(Buffer* uniform, ShaderStage stage)
{
	mUniform = uniform;
	mStage = stage;
	mType = ResourceFlag::RESOURCE_TYPE_IMAGE;
}

void Binding::SetSampler(Sampler* sampler, ShaderStage stage)
{
	mSampler = sampler;
	mStage = stage;
	mType = ResourceFlag::RESOURCE_TYPE_IMAGE;
}

} /* namespace Render */
