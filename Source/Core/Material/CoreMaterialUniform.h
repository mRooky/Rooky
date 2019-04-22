/*
 * CoreMaterialUniform.h
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_COREMATERIALUNIFORM_H_
#define SOURCE_CORE_MATERIAL_COREMATERIALUNIFORM_H_

#include "GHIBinding.hpp"
#include "CoreMaterialData.h"
#include <array>

namespace Core
{
class Uniform;
class MaterialUniform
{
public:
	MaterialUniform(void);
	~MaterialUniform(void);

public:
	void UpdateUniformData(void);

public:
	GHI::Binding GetBinding(void) const;

public:
	inline void SetUniform(Uniform* uniform, size_t offset)
	{
		mOffset = offset;
		mUniform = uniform;
	}

public:
	inline size_t GetOffset(void) const { return mOffset; }
	inline Uniform* GetUniform(void) const { return mUniform; }
	inline bool IsValid(void) const { return mUniform != nullptr; }

protected:
	size_t mOffset = 0;
	Uniform* mUniform = nullptr;
	MaterialData mUniformData = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_COREMATERIALUNIFORM_H_ */
