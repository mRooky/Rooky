/*
 * RenderInline.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERINLINE_H_
#define SOURCE_CORE_RENDER_RENDERINLINE_H_

#include <RenderEnum.h>
#include <cstddef>
#include <cassert>

namespace Render
{

static inline uint32_t Bit(uint32_t pos)
{
	return 1u << pos;
}

}

#endif /* SOURCE_CORE_RENDER_RENDERINLINE_H_ */
