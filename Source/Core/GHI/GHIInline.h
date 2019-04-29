/*
 * RenderInline.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERINLINE_H_
#define SOURCE_CORE_GHI_RENDERINLINE_H_

#include "GHIEnum.h"
#include <cstddef>
#include <cassert>

namespace GHI
{

static inline size_t GetIndexTypeSize(IndexType type)
{
	switch(type)
	{
	case IndexType::INDEX_TYPE_U16:
		return 2;
	case IndexType::INDEX_TYPE_U32:
		return 4;
	default:
		assert(false);
		return 0;
	}
}

static inline const char* GetIndexTypeName(IndexType type)
{
	switch(type)
	{
	case IndexType::INDEX_TYPE_U16:
		return "INDEX_TYPE_U16";
	case IndexType::INDEX_TYPE_U32:
		return "INDEX_TYPE_U32";
	default:
		assert(false);
		return "Unknown";
	}
}

}

#endif /* SOURCE_CORE_GHI_RENDERINLINE_H_ */
