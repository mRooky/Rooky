/*
 * CoreMaterialData.h
 *
 *  Created on: Apr 11, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MATERIAL_COREMATERIALDATA_H_
#define SOURCE_CORE_MATERIAL_COREMATERIALDATA_H_

#include "RenderVector.hpp"

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
	void SetShininess(Render::Real shininess);
	void SetAmbient(const Render::ColorValue& color);
	void SetDiffuse(const Render::ColorValue& color);
	void SetSpecular(const Render::ColorValue& color);
	void SetEmissive(const Render::ColorValue& color);

public:
	inline Render::Real GetShininess(void) const { return mShininess; }
	inline const Render::ColorValue GetAmbient(void) const { return mAmbient; }
	inline const Render::ColorValue GetDiffuse(void) const { return mDiffuse; }
	inline const Render::ColorValue GetSpecular(void) const { return mSpecular; }
	inline const Render::ColorValue GetEmissive(void) const { return mEmissive; }

public:
	inline bool IsDirty(void) const { return mDirty ;}
	inline size_t GetDataSize(void) const { return MaterialDataSize; }
	inline const void* GetDataMemory(void) const { return &mShininess; }

protected:
	bool mDirty = false;

protected:
	Render::Real mShininess = 0.0f;
	Render::ColorValue mAmbient = {};
	Render::ColorValue mDiffuse = {};
	Render::ColorValue mSpecular = {};
	Render::ColorValue mEmissive = {};

private:
	static const size_t MaterialDataSize = 32;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MATERIAL_COREMATERIALDATA_H_ */
