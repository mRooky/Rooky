/*
 * CoreMaterial.cpp
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#include "CoreMaterial.h"

namespace Core
{

Material::Material(MaterialManager* manager):
		mManager(manager)
{
}

Material::~Material(void)
{
}

} /* namespace Core */
