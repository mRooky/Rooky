/*
 * CoreMaterial.h
 *
 *  Created on: Feb 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_COREMATERIAL_H_
#define SOURCE_CORE_MATERIAL_COREMATERIAL_H_

#include "CoreShaderResource.h"
#include "CoreMaterialUniform.h"
#include "../CoreBase.h"
#include "../Kernel/KernelFixedVector.h"

namespace Core
{
class MaterialManager;
class Material : Base
{
	friend class MaterialManager;
protected:
	explicit Material(MaterialManager* manager);

public:
	virtual ~Material(void) override;

public:
	inline void SetShaderResource(size_t index, ShaderResource* resource)
	{
		mShaderResources.SetElement(index, resource);
	}

public:
	inline MaterialUniform* GetUniform(void) { return &mMaterialUniform; }
	inline ShaderResource* GetShaderResource(size_t index)
	{
		return mShaderResources.GetElementAt(index);
	}

public:
	inline MaterialManager* GetManager(void) const { return mManager; }

protected:
	MaterialManager* mManager = nullptr;

protected:
	MaterialUniform mMaterialUniform = {};
	Kernel::FixedVector<ShaderResource*, 5> mShaderResources;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_COREMATERIAL_H_ */
