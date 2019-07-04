/*
 *       Filename:  GLTFBRDF.cpp
 *
 */

#include "GLTFBRDF.h"
#include "../Core/GHI/GHIShader.h"

namespace GLTF
{

BRDF::BRDF(Manager* manager):
	Texture(manager)
{

}

BRDF::~BRDF(void)
{

}

void BRDF::Create(GHI::CommandList* command, const char* vert, const char* frag, uint32_t dimension)
{

}

}
