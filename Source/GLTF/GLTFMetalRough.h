/*
 * =====================================================================================
 *
 *       Filename:  GLTFMetalRough.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_METAL_ROUGH_TEXTURE_H
#define SOURCE_GLTF_METAL_ROUGH_TEXTURE_H

#include "GLTFTexture.h"

namespace GLTF
{

class MetalRough : public Texture
{
public:
	MetalRough(void);
	~MetalRough(void) override;

public:
	inline void SetMetalFactor(float factor) { mMetalFactor = factor; }
	inline void SetRoughFactor(float factor) { mRoughFactor = factor; }

public:
	inline float GetMetalFactor(void) const { return mMetalFactor; }
	inline float GetToughFactor(void) const { return mRoughFactor; }

protected:
	float mMetalFactor = 1.0f;
	float mRoughFactor = 1.0f;
};

}


#endif
