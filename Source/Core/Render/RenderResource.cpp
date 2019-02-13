/*
 * RenderResource.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "RenderResource.h"
#include <cassert>

namespace Render
{

Resource::Resource(Context* context):
		Object(context)
{
}

Resource::~Resource(void)
{
}

} /* namespace Render */
