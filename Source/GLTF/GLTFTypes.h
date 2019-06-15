/*
 * =====================================================================================
 *
 *       Filename:  GLTFTypes.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_TYPES_H
#define SOURCE_GLTF_TYPES_H

#include <cstdint>

namespace GLTF
{

enum AlphaMode : uint32_t
{
	MASK,
	BLEND,
	UNKNOWN
};

enum class WorkFlow : uint32_t
{
	METALLIC_ROUGHNESS,
	SPECULAR_GLOSSINESS,
	UNKNOWN
};

}

#endif
