/*
 * =====================================================================================
 *
 *       Filename:  GlTFDiffuse.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_DIFFUSE_TEXTURE_H
#define SOURCE_GLTF_DIFFUSE_TEXTURE_H

#include "GLTFTexture.h"

namespace GLTF
{

class Diffuse : public Texture
{
public:
	Diffuse(Manager* manager);
	virtual ~Diffuse(void) override;

protected:


};

}

#endif
