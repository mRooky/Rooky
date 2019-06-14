/*
 * RenderTypes.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERENUM_H_
#define SOURCE_CORE_GHI_RENDERENUM_H_

#include <cstdint>

namespace GHI
{
	enum class IndexType : uint32_t
	{
		U16,
		U32,
		UNKNOWN = ~0u
	};

}

#endif /* SOURCE_CORE_GHI_RENDERENUM_H_ */
