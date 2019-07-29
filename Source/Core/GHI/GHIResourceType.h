/*
 * =====================================================================================
 *
 *       Filename:  GHIResourceType.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_CORE_GHI_RESOURCE_TYPE_H
#define SOURCE_CORE_GHI_RESOURCE_TYPE_H

#include <cstdint>

namespace GHI
{

enum ResourceType : uint32_t
{
	IMAGE   = 0,
	BUFFER  = 1,
	SAMPLER = 2,
	UNKNOWN = ~0u
};

}

#endif
