/*
 * CoreMaterialData.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: rookyma
 */

#include "CoreMaterialData.h"
#include "../CoreUniform.h"
#include <cassert>
#include <cstring>

namespace Core
{

MaterialData::MaterialData(void)
{
}

MaterialData::~MaterialData(void)
{
}

void MaterialData::SetShininess(float shininess)
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
			std::memcpy(write_ptr, &mShininess, sizeof(mShininess));
			write_ptr += sizeof(mShininess);
			std::memcpy(write_ptr, &mAmbient, sizeof(mAmbient));
			write_ptr += sizeof(mAmbient);
			std::memcpy(write_ptr, &mDiffuse, sizeof(mDiffuse));
			write_ptr += sizeof(mDiffuse);
			std::memcpy(write_ptr, &mSpecular, sizeof(mSpecular));
			write_ptr += sizeof(mSpecular);
			std::memcpy(write_ptr, &mEmissive, sizeof(mEmissive));
		}
		uniform->Write(buffer, offset, MaterialDataSize);
		mDirty = false;
	}
}

} /* namespace Core */
