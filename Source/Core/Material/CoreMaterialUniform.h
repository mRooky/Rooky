/*
 * CoreMaterialUniform.h
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_COREMATERIALUNIFORM_H_
#define SOURCE_CORE_MATERIAL_COREMATERIALUNIFORM_H_

#include "RenderVector.hpp"

namespace Core
{
class Uniform;
class MaterialUniform
{
public:
	MaterialUniform(void);
	~MaterialUniform(void);

public:
	inline void SetUniform(Uniform* uniform, size_t offset)
	{
		mOffset = offset;
		mUniform = uniform;
	}
	inline size_t GetOffset(void) const { return mOffset; }
	inline Uniform* GetUniform(void) const { return mUniform; }

protected:
	size_t mOffset = 0;
	Uniform* mUniform = nullptr;

protected: // uniform data
	const size_t mSize = 128;

};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_COREMATERIALUNIFORM_H_ */
