/*
 * Sampler.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "RenderSampler.h"

namespace Render
{

Sampler::Sampler(Device* device):
		Resource(device)
{
	mType = ResourceType::RESOURCE_TYPE_SAMPLER;
}

Sampler::~Sampler(void)
{
}

} /* namespace Render */
