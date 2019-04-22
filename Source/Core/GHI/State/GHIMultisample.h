/*
 * RenderMultisample.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERSTATE_RENDERMULTISAMPLE_H_
#define SOURCE_CORE_GHI_RENDERSTATE_RENDERMULTISAMPLE_H_

#include "GHIStateEnum.h"

namespace GHI
{

class Multisample
{
public:
	Multisample(void) = default;
	~Multisample(void) = default;

	inline bool operator==(const Multisample& other) const
	{
		return rasterizationSamples == other.rasterizationSamples;
	}

public:
	uint32_t rasterizationSamples = 1;
};

}

#endif /* SOURCE_CORE_GHI_RENDERSTATE_RENDERMULTISAMPLE_H_ */
