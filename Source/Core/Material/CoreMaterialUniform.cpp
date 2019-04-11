/*
 * CoreMaterialUniform.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#include "CoreMaterialUniform.h"
#include "CoreUniform.h"
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

Render::Binding MaterialUniform::GetBinding(void) const
{
	assert(IsValid());
	Render::Binding binding;
	auto render_resource = mUniform->GetRenderResource();
	auto shader_stage = Render::ShaderStage::SHADER_STAGE_VERTEX;
	binding.SetResource(render_resource, shader_stage);
	return binding;
}

} /* namespace Core */
