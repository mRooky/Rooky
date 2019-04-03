/*
 * CoreMaterialManager.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_COREMATERIALMANAGER_H_
#define SOURCE_CORE_MANAGER_COREMATERIALMANAGER_H_

#include "CoreObject.h"
#include <vector>

namespace Core
{
class Material;
class ShaderResource;
class MaterialManager: public Object
{
public:
	explicit MaterialManager(System* system);
	virtual ~MaterialManager(void) override;

public:
	Material* GetMaterial(const char* name);
	Material* CreateMaterial(const char* name);

protected:
	std::vector<Material*> mMaterials;
	std::vector<ShaderResource*> mShaderResources;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREMATERIALMANAGER_H_ */
