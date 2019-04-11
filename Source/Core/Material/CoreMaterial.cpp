/*
 * CoreMaterial.cpp
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#include "CoreMaterial.h"
#include "CoreUniform.h"
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
}

} /* namespace Core */
