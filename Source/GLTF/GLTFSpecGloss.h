/*
 * =====================================================================================
 *
 *       Filename:  GLTFSpecGloss.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_SPEC_GLOSS_TEXTURE_H
#define SOURCE_GLTF_SPEC_GLOSS_TEXTURE_H

#include "GLTFTexture.h"

namespace GLTF
{

class SpecGloss : public Texture
{
public:
	SpecGloss(void);
	~SpecGloss(void) override;

protected:

};

}

#endif