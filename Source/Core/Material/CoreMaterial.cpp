/*
 * CoreMaterial.cpp
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#include "CoreMaterial.h"
#include <cassert>

namespace Core
{

Material::Material(MaterialManager* manager):
		mManager(manager)
{
}

Material::~Material(void)
{
	mManager = nullptr;
	mSubMaterials.clear();
}

void Material::SetSubMaterial(size_t index, Material* material)
{
	assert(index < mSubMaterials.size());
	if (index < mSubMaterials.size())
	{
		mSubMaterials.at(index) = material;
	}
}

} /* namespace Core */
