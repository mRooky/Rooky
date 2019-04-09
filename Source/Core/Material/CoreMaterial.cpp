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
}

std::vector<Render::Binding> Material::GetBindings(void) const
{
	std::vector<Render::Binding> bindings;
	assert(false);
	return bindings;
}

} /* namespace Core */
