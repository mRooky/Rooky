/*
 * CoreMaterialManager.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#include "CoreMaterialManager.h"
#include "CoreMaterial.h"

namespace Core
{

MaterialManager::MaterialManager(System* system):
		Object(system)
{
}

MaterialManager::~MaterialManager(void)
{
}

Material* MaterialManager::GetMaterial(const char* name)
{
	const std::string mtl_name(name);
	for (auto material : mMaterials)
	{
		auto curr_name = material->GetName();
		if (mtl_name == curr_name)
		{
			return material;
		}
	}
	return nullptr;
}

Material* MaterialManager::CreateMaterial(const char* name)
{
	Material* material = new Material(this);
	material->SetName(name);
	mMaterials.push_back(material);
	return material;
}

} /* namespace Core */
