/*
 * CoreMaterialManager.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#include "CoreMaterial.h"
#include "CoreMaterialManager.h"
#include "CoreShaderResource.h"

#include "UtilityRelease.h"

namespace Core
{

MaterialManager::MaterialManager(System* system):
		Interface(system)
{
}

MaterialManager::~MaterialManager(void)
{
	Utility::Release(mMaterials);
	Utility::Release(mShaderResources);
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
