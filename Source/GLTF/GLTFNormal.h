/*
 * =====================================================================================
 *
 *       Filename:  GLTFNormal.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_NORMAL_TEXTURE_H
#define SOURCE_GLTF_NORMAL_TEXTURE_H

#include "GLTFTexture.h"

namespace GLTF
{

class Normal : public Texture
{
public:
	Normal(void);
	~Normal(void) override;

public:
	inline void SetScale(float scale) { mScale = scale; }

public:
	inline float GetScale(void) const { return mScale; }

protected:
	float mScale = 2.0f;

};

}


#endif
