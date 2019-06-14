/*
 * CoreMaterialUniform.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#include "CoreMaterialUniform.h"
#include "../CoreUniform.h"
#include <cstring>
#include <cassert>

namespace Core
{

MaterialUniform::MaterialUniform(void)
{
}

MaterialUniform::~MaterialUniform(void)
{
	mOffset = 0;
	mUniform = nullptr;
}

GHI::Binding MaterialUniform::GetBinding(void) const
{
	assert(IsValid());
	GHI::Binding binding;
	auto render_resource = mUniform->GetRenderResource();
	auto shader_stage = GHI::ShaderStage::VERTEX;
	binding.SetResource(render_resource, shader_stage);
	return binding;
}

void MaterialUniform::UpdateUniformData(void)
{
	assert(mUniform != nullptr);
	mUniformData.UpdateUniform(mUniform, mOffset);
}

} /* namespace Core */
