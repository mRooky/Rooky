/*
 * RenderSamplerState.h
 *
 *  Created on: Mar 27, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERSAMPLERSTATE_H_
#define SOURCE_CORE_GHI_RENDERSAMPLERSTATE_H_

#include <cstdint>

namespace GHI
{

enum class FilterType : uint32_t
{
	NEAREST,
	LINEAR,
	CUBIC_IMG,
	UNKNOWN = ~0U
};

enum class MipmapMode : uint32_t
{
    NEAREST,
    LINEAR,
    UNKNOWN = ~0U
};

enum class AddressMode : uint32_t
{
    REPEAT,
    MIRRORED_REPEAT,
    CLAMP_TO_EDGE,
    CLAMP_TO_BORDER,
    MIRROR_CLAMP_TO_EDGE,
    UNKNOWN = ~0U
};

}

#endif /* SOURCE_CORE_GHI_RENDERSAMPLERSTATE_H_ */
