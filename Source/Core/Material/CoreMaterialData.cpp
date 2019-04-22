/*
 * CoreMaterialData.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: rookyma
 */

#include "CoreMaterialData.h"
#include "CoreUniform.h"
#include "UtilityMemory.h"
#include <cassert>

namespace Core
{

MaterialData::MaterialData(void)
{
}

MaterialData::~MaterialData(void)
{
}

void MaterialData::SetShininess(Math::Real shininess)
{
	mDirty = true;
	mShininess = shininess;
}

void MaterialData::SetAmbient(const Math::ColorValue& color)
{
	mDirty = true;
	mAmbient = color;
}

void MaterialData::SetDiffuse(const Math::ColorValue& color)
{
	mDirty = true;
	mDiffuse = color;
}

void MaterialData::SetSpecular(const Math::ColorValue& color)
{
	mDirty = true;
	mSpecular = color;
}

void MaterialData::SetEmissive(const Math::ColorValue& color)
{
	mDirty = true;
	mEmissive = color;
}

void MaterialData::UpdateUniform(Uniform* uniform, size_t offset)
{
	if (mDirty)
	{
		uint8_t buffer[MaterialDataSize];
		std::memset(buffer, 0, MaterialDataSize);
		{
			uint8_t* write_ptr = buffer;
			write_ptr += Utility::Memcpy(write_ptr, mShininess);
			write_ptr += Utility::Memcpy(write_ptr, mAmbient);
			write_ptr += Utility::Memcpy(write_ptr, mDiffuse);
			write_ptr += Utility::Memcpy(write_ptr, mSpecular);
			write_ptr += Utility::Memcpy(write_ptr, mEmissive);
		}
		uniform->Write(buffer, offset, MaterialDataSize);
		mDirty = false;
	}
}

} /* namespace Core */
