/*
 * CoreVertexResource.cpp
 *
 *  Created on: Apr 28, 2019
 *      Author: rookyma
 */

#include "CoreVertexResource.h"
#include "CoreUniform.h"

namespace Core
{

VertexResource::VertexResource(void)
{
}

VertexResource::~VertexResource(void)
{
}

void VertexResource::SetUniform(Uniform* uniform, size_t offset)
{
	mOffset = offset;
	mUniform = uniform;
	auto resource = uniform->GetRenderResource();
	auto stage = GHI::ShaderStage::SHADER_STAGE_VERTEX;
	GHI::Binding binding;
	binding.SetResource(resource, stage);
	mBindings.push_back(binding);
}

} /* namespace Core */
