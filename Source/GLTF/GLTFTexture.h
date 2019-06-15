/*
 * =====================================================================================
 *
 *       Filename:  GLTFBaseTexture.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_BASE_TEXTURE_H
#define SOURCE_GLTF_BASE_TEXTURE_H

#include "../Core/CoreTexture.h"

namespace GLTF
{

class Texture
{
public:
	Texture(void) {}
	virtual ~Texture(void) {}

public:
	inline Core::Texture* GetTexture(void) const { return mTexture; }

protected:
	Core::Texture* mTexture = nullptr;

};

}

#endif
