/*
 * RenderUtility.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERUTILITY_H_
#define SOURCE_CORE_RENDER_RENDERUTILITY_H_

#include "RenderEnum.h"
#include <cstddef>
#include <cassert>

namespace Render
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

}
#endif /* SOURCE_CORE_RENDER_RENDERUTILITY_H_ */
