/*
 * RenderMultisample.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_STATE_RENDERMULTISAMPLE_H_
#define SOURCE_CORE_RENDER_STATE_RENDERMULTISAMPLE_H_

#include "RenderState.h"

namespace Render
{

class Multisample
{
public:
	Multisample(void) = default;
	~Multisample(void) = default;

public:
	uint32_t rasterizationSamples = 1;
};

}

#endif /* SOURCE_CORE_RENDER_STATE_RENDERMULTISAMPLE_H_ */
