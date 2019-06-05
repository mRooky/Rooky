/*
 *
 *       Filename:  GLTFMaterial.h
 *
 */

#include "../Core/CoreTexture.h"
#include "../Core/Math/MathVector.h"

namespace GLTF
{

enum class WorkFlow : uint32_t
{
	METALLIC_ROUGHNESS,
	SPECULAR_GLOSSINESS
};

class Material
{
public:
	Material(void);
	~Material(void);

public:
	inline void SetAlphaCutoff(float cutoff) { mAplhaCutoff = cutoff; }
	inline void SetMetallicFactor(float factor) { mMetallicFactor = factor; }
	inline void SetRoughnessFactor(float factor) { mRoughnessFactor = factor; }
	inline float GetAlphaCutoff(void) const { return mAplhaCutoff; }
	inline float GetMetallicFactor(void) const { return mMetallicFactor; }
	inline float GetRoughnessFactor(void) const { return mRoughnessFactor; }

public:
	inline void SetEmissiveFactor(Math::Vector4f& factor) { mEmissiveFactor = factor; }
	inline void SetBaseColorFactor(Math::Vector4f& factor) { mBaseColorFactor = factor; }
	inline const Math::Vector4f& GetEmissiveFactor(void) const { return mEmissiveFactor; }
	inline const Math::Vector4f& GetBaseColorFactor(void) const { return  mBaseColorFactor; }

public:
	inline void SetBaseColor(Core::Texture* texture) { mBaseColor = texture; }
	inline void SetMetallicRoughness(Core::Texture* texture) { mMetallicRoughness = texture; }
	inline void SetNormal(Core::Texture* texture) { mNormal = texture; }
	inline void SetOcclusion(Core::Texture* texture) { mOcclusion = texture; }
	inline void SetEmissive(Core::Texture* texture) { mEmissive = texture; }
	inline Core::Texture* GetBaseColor(void) const { return mBaseColor; }
	inline Core::Texture* GetMetallicRoughness(void) const { return mMetallicRoughness; }
	inline Core::Texture* GetNormal(void) const { return mNormal; }
	inline Core::Texture* GetOcclusion(void) const { return mOcclusion; }
	inline Core::Texture* GetEmissive(void) const { return mEmissive; }

public:
	inline void SetWorkFlow(WorkFlow work) { mWorkFlow = work; }
	inline WorkFlow GetWorkFlow(void) const { return mWorkFlow; }

protected:
	float mAplhaCutoff = 1.0f;
	float mMetallicFactor = 1.0f;
	float mRoughnessFactor = 1.0f;

protected:
	Math::Vector4f mEmissiveFactor = {};
	Math::Vector4f mBaseColorFactor = {};

protected:
	Core::Texture* mBaseColor = nullptr;
	Core::Texture* mMetallicRoughness = nullptr;
	Core::Texture* mNormal= nullptr;
	Core::Texture* mOcclusion = nullptr;
	Core::Texture* mEmissive = nullptr;

protected:
	WorkFlow mWorkFlow = WorkFlow::METALLIC_ROUGHNESS;

};

}
