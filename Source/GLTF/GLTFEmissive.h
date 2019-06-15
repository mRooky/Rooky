/*
 * =====================================================================================
 *
 *       Filename:  GLTFEmissive.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_EMISSIVE_TEXTURE_H
#define SOURCE_GLTF_EMISSIVE_TEXTURE_H

#include "GLTFTexture.h"
#include "../Core/Math/MathVector.h"

namespace GLTF
{

class Emissive : public Texture
{
public:
	Emissive(void);
	~Emissive(void) override;

public:
	inline void SetFactor(Math::Vector3f& factor) { mFactor = factor; }

public:
	inline const Math::Vector3f& GetFactor(void) const { return mFactor; }

protected:
	Math::Vector3f mFactor = {};

};

}

#endif
