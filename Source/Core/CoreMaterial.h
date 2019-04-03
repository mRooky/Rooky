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
protected:
	explicit Material(MaterialManager* manager);
	virtual ~Material(void);

public:
	inline MaterialManager* GetManager(void) const { return mManager; }

protected:
	MaterialManager* mManager = nullptr;
	std::vector<Material*> mSubMaterials;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMATERIAL_H_ */
