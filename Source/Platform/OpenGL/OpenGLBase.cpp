/*
 * OpenGLBase.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "OpenGLBase.h"
#include <cassert>

namespace OpenGL
{

Base::Base(void)
{
}

Base::~Base(void)
{
}

const char* Base::GetResultName(GLenum result)
{
#define GL_CASE(x) case x : return #x
	switch(result)
	{
	GL_CASE(GL_NO_ERROR);
	GL_CASE(GL_INVALID_ENUM);
	GL_CASE(GL_INVALID_VALUE);
	GL_CASE(GL_INVALID_OPERATION);
	GL_CASE(GL_STACK_OVERFLOW);
	GL_CASE(GL_STACK_UNDERFLOW);
	GL_CASE(GL_OUT_OF_MEMORY);
	GL_CASE(GL_INVALID_FRAMEBUFFER_OPERATION);
	GL_CASE(GL_CONTEXT_LOST);
	default:
		assert(false);
		return "GL_UNKNOWN";
	}
#undef GL_CASE
}

} /* namespace OpenGL */
