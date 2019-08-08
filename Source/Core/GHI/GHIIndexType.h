/*
 * RenderTypes.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERENUM_H_
#define SOURCE_CORE_GHI_RENDERENUM_H_

#include <cstdint>
#include <cstddef>

namespace GHI
{

enum class IndexType : uint32_t
{
	U16,
	U32,
	UNKNOWN = ~0u
};

static inline size_t GetIndexTypeSize(IndexType type)
{
	switch(type)
	{
	case IndexType::U16:
		return 2;
	case IndexType::U32:
		return 4;
	default:
		return 0;
	}
}

static inline const char* GetIndexTypeName(IndexType type)
{
	switch(type)
	{
	case IndexType::U16:
		return "INDEX_TYPE_U16";
	case IndexType::U32:
		return "INDEX_TYPE_U32";
	default:
		return "Unknown";
	}
}

}

#endif /* SOURCE_CORE_GHI_RENDERENUM_H_ */
