/*
 * CoreMaterialData.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: rookyma
 */

#include "CoreMaterialData.h"
#include <cstring>
#include <cassert>

namespace Core
{

MaterialData::MaterialData(void)
{
}

MaterialData::~MaterialData(void)
{
}

void MaterialData::UpdateUniform(Uniform* uniform, size_t offset)
{
	if (mDirty)
	{
		assert(false);
		mDirty = false;
	}
}

void MaterialData::SetShininess(Render::Real shininess)
{
	mDirty = true;
	mShininess = shininess;
}

void MaterialData::SetAmbient(const Render::ColorValue& color)
{
	mDirty = true;
	mAmbient = color;
}

void MaterialData::SetDiffuse(const Render::ColorValue& color)
{
	mDirty = true;
	mDiffuse = color;
}

void MaterialData::SetSpecular(const Render::ColorValue& color)
{
	mDirty = true;
	mSpecular = color;
}

void MaterialData::SetEmissive(const Render::ColorValue& color)
{
	mDirty = true;
	mEmissive = color;
}

} /* namespace Core */
