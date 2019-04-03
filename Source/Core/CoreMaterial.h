/*
 * CoreMaterial.h
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMATERIAL_H_
#define SOURCE_CORE_COREMATERIAL_H_

#include "CoreBase.h"
#include <vector>

namespace Core
{
class MaterialManager;
class Material : Base
{
	friend class MaterialManager;
protected:
	explicit Material(MaterialManager* manager);
	virtual ~Material(void);

public:
	void SetSubMaterial(size_t index, Material* material);

public:
	inline void AppendSubMaterial(Material* material) { mSubMaterials.push_back(material); }

public:
	inline size_t GetSubMaterialCount(void) const { return mSubMaterials.size(); }
	inline Material* GetSubMaterial(size_t index) const { return mSubMaterials.at(index); }

public:
	inline MaterialManager* GetManager(void) const { return mManager; }

protected:
	MaterialManager* mManager = nullptr;
	std::vector<Material*> mSubMaterials;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMATERIAL_H_ */
