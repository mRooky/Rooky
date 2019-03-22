/*
 * Sampler.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderSampler.h"

namespace Render
{

Sampler::Sampler(Context* context):
		Resource(context)
{
	mType = ResourceType::RESOURCE_TYPE_SAMPLER;
}

Sampler::~Sampler(void)
{
}

} /* namespace Render */
