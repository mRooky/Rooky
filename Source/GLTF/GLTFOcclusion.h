/*
 * =====================================================================================
 *
 *       Filename:  GLTFOcclusion.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_OCCLUSION_TEXTURE_H
#define SOURCE_GLTF_OCCLUSION_TEXTURE_H

#include "GLTFTexture.h"

namespace GLTF
{

class Occlusion : public Texture
{
public:
	Occlusion(Manager* manager);
	virtual ~Occlusion(void) override;

protected:

};

}


#endif
