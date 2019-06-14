/*
 * =====================================================================================
 *
 *       Filename:  GHIShaderTypes.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_GHI_SHADER_TYPES_H
#define SOURCE_CORE_GHI_SHADER_TYPES_H

#include <cstdint>

namespace GHI
{
	enum class ShaderType : uint32_t
	{
		VERTEX,
		HULL,
		DOMAIN,
		GEOMETRY,
		FRAGMENT,
		COMPUTE,
		UNKNOWN = ~0U
	};

	enum class ShaderStage : uint32_t
	{
		VERTEX,
		HULL,
		DOMAIN,
		GEOMETRY,
		FRAGMENT,
		COMPUTE,
		ALL,
		UNKNOWN = ~0u
	};

}

#endif
