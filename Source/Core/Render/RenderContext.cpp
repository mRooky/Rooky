/*
 * RenderContext.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "RenderContext.h"
#include "RenderFactory.h"

namespace Render
{

Context::Context(void)
{
}

Context::~Context(void)
{
	delete mFactory;
	mFactory = nullptr;
}

} /* namespace Render */
