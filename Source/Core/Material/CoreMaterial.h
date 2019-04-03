/*
 * CoreMaterial.h
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_COREMATERIAL_H_
#define SOURCE_CORE_MATERIAL_COREMATERIAL_H_

#include "CoreShaderResource.h"
#include "CoreBase.h"
#include <array>

namespace Core
{
class MaterialManager;
class Material : Base
{
	friend class MaterialManager;
protected:
	explicit Material(MaterialManager* manager);

public:
	virtual ~Material(void);

public:
	void SetSubMaterial(size_t index, Material* material);

public:
	inline size_t GetSubMaterialCount(void) const { return mSubMaterials.size(); }
	inline Material* GetSubMaterial(size_t index) const { return mSubMaterials.at(index); }
	inline void AppendSubMaterial(Material* material) { mSubMaterials.push_back(material); }

public:
	inline ShaderResource* GetShaderResource(size_t index) { return mShaderResources.at(index); }
	inline void SetShaderResource(size_t index, ShaderResource* resource) { mShaderResources.at(index) = resource; }

public:
	inline MaterialManager* GetManager(void) const { return mManager; }

protected:
	MaterialManager* mManager = nullptr;
	std::vector<Material*> mSubMaterials;
	std::array<ShaderResource*, 5> mShaderResources;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_COREMATERIAL_H_ */
