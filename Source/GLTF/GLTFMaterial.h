/*
 *
 *       Filename:  GLTFMaterial.h
 *
 */

#ifndef SOURCE_GLTF_MATERIAL_H
#define SOURCE_GLTF_MATERIAL_H

#include "GLTFUsageType.h"
#include "GLTFClasses.h"

namespace GLTF
{

class Material
{
public:
	Material(void);
	~Material(void);

public:
	void Create(const UsageType& usage);

public:
	inline void SetAlphaCutoff(float cutoff) { mAlphaCutoff = cutoff; }
	inline float GetAlphaCutoff(void) const { return mAlphaCutoff; }

public:
	inline Normal* GetNormal(void) const { return mNormal; }
	inline Emissive* GetEmissive(void) const { return mEmissive; }
	inline Occlusion* GetOcclusion(void) const { return mOcclusion; }
	inline BaseColor* GetBaseColor(void) const { return mBaseColor; }
	inline MetalRough* GetMetallicRoughness(void) const { return mMetallicRoughness; }

public:
	inline void SetWorkFlow(WorkFlow work) { mWorkFlow = work; }
	inline WorkFlow GetWorkFlow(void) const { return mWorkFlow; }

protected:
	float mAlphaCutoff = 1.0f;

protected:
	union
	{
		Diffuse* mDeffuse;
		BaseColor* mBaseColor = nullptr;
	};

	union
	{
		SpecGloss* mSpecGloss;
		MetalRough* mMetallicRoughness = nullptr;
	};

	Normal* mNormal= nullptr;
	Emissive* mEmissive = nullptr;
	Occlusion* mOcclusion = nullptr;

protected:
	UsageType mUsageType = {};
	AlphaMode mAlphaMode = AlphaMode::MASK;
	WorkFlow mWorkFlow = WorkFlow::METALLIC_ROUGHNESS;

};

}


#endif
