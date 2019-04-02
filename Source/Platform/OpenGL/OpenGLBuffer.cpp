/*
 * OpenGLBuffer.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "OpenGLBuffer.h"

namespace OpenGL
{

Buffer::Buffer(void)
{
	glGenBuffers(1, &mID);
}

Buffer::~Buffer(void)
{
	glDeleteBuffers(1, &mID);
}

void Buffer::Create(size_t size, const void* src)
{
	glBindBuffer(GL_ARRAY_BUFFER, mID);
	glBufferData(GL_ARRAY_BUFFER, size, NULL, GL_DYNAMIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, size, src);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

} /* namespace OpenGL */
