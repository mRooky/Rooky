/*
 * CoreMaterialData.h
 *
 *  Created on: Apr 11, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_COREMATERIALDATA_H_
#define SOURCE_CORE_MATERIAL_COREMATERIALDATA_H_

#include "MathVector.h"

namespace Core
{
class Uniform;
class MaterialData
{
public:
	MaterialData(void);
	~MaterialData(void);

public:
	void UpdateUniform(Uniform* uniform, size_t offset);

public:
	void SetShininess(float shininess);
	void SetAmbient(const Math::ColorValue& color);
	void SetDiffuse(const Math::ColorValue& color);
	void SetSpecular(const Math::ColorValue& color);
	void SetEmissive(const Math::ColorValue& color);

public:
	inline float GetShininess(void) const { return mShininess; }
	inline const Math::ColorValue& GetAmbient(void) const { return mAmbient; }
	inline const Math::ColorValue& GetDiffuse(void) const { return mDiffuse; }
	inline const Math::ColorValue& GetSpecular(void) const { return mSpecular; }
	inline const Math::ColorValue& GetEmissive(void) const { return mEmissive; }

public:
	inline bool IsDirty(void) const { return mDirty ;}
	inline size_t GetDataSize(void) const { return MaterialDataSize; }
	inline const void* GetDataMemory(void) const { return &mShininess; }

protected:
	bool mDirty = false;

protected:
	float mShininess = 0.0f;
	Math::ColorValue mAmbient;
	Math::ColorValue mDiffuse;
	Math::ColorValue mSpecular;
	Math::ColorValue mEmissive;

private:
	static constexpr size_t MaterialDataSize = 256;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_COREMATERIALDATA_H_ */
