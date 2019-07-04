/*
 *       Filename:  GLTFBRDF.h
 *
 */
#ifndef SOURCE_GLTF_BRDF_TEXTURE_H
#define SOURCE_GLTF_BRDF_TEXTURE_H

#include "GLTFTexture.h"
#include <cstdint>

namespace GLTF
{

class BRDF : public Texture
{
public:
	BRDF(Manager* manager);
	virtual ~BRDF(void) override;

public:
	void Create(GHI::CommandList* command, const char* vert, const char* frag, uint32_t dimension);

};

}

#endif
