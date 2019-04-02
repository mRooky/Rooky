/*
 * OpenGLContext.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "OpenGLContext.h"
#include <iostream>
#include <cassert>

namespace OpenGL
{

Context::Context(void)
{
}

Context::~Context(void)
{
}

void Context::Create(void)
{
	assert(mResult == ~0u);
	mResult = glewInit();
	std::cout << "OpenGL Init : " << Base::GetResultName(mResult) << std::endl;
}

} /* namespace OpenGL */
