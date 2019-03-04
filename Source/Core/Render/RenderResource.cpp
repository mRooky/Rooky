/*
 * RenderResource.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "RenderResource.h"
#include <cassert>

namespace Render
{

Resource::Resource(void)
{
}

Resource::~Resource(void)
{
}

bool Resource::IsValid(void) const
{
	bool valid = mObject != nullptr;
	valid = valid && mStage!= ShaderStage::SHADER_STAGE_UNKNOWN;
	valid = valid && mType != ResourceType::RESOURCE_TYPE_COMMON;
	return valid;
}

Resource& Resource::operator=(const Resource& other)
{
	mType = other.mType;
	mObject = other.mObject;
	mStage = other.mStage;
	return *this;
}

void Resource::SetImage(Image* image, ShaderStage stage)
{
	mImage = image;
	mStage = stage;
	mType = ResourceType::RESOURCE_TYPE_IMAGE;
}

void Resource::SetUniform(Buffer* uniform, ShaderStage stage)
{
	mUniform = uniform;
	mStage = stage;
	mType = ResourceType::RESOURCE_TYPE_IMAGE;
}

void Resource::SetSampler(Sampler* sampler, ShaderStage stage)
{
	mSampler = sampler;
	mStage = stage;
	mType = ResourceType::RESOURCE_TYPE_IMAGE;
}

} /* namespace Render */
