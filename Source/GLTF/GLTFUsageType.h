/*
 * =====================================================================================
 *
 *       Filename:  GLTFMask.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_MASK_H
#define SOURCE_GLTF_MASK_H

#include "GLTFTypes.h"

namespace GLTF
{

class UsageType
{
public:
	UsageType(void) {}
	~UsageType(void) {}

public:
	union
	{
		struct
		{
			uint8_t combine     : 1;
			// Common
			uint8_t baseColor   : 1;
			uint8_t metallic    : 1;
			uint8_t roughness   : 1;
			// Extension
			uint8_t diffuse     : 1;
			uint8_t specular    : 1;
			uint8_t gloss       : 1;
			// Public
			uint8_t emissive    : 1;
			uint8_t occlusion   : 1;
			uint8_t normal      : 1;
			// Reserve
			uint8_t reserve     : 6;
		};
		uint16_t m_allMask = 0;
	};
	WorkFlow workFlow = WorkFlow::METALLIC_ROUGHNESS;
};

}

#endif
