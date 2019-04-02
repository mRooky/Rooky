/*
 * OpenGLVertexArray.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "OpenGLVertexArray.h"

namespace OpenGL
{

VertexArray::VertexArray(void)
{
	glGenVertexArrays(1, &mID);
}

VertexArray::~VertexArray(void)
{
	glDeleteVertexArrays(1, &mID);
}

void VertexArray::Binding(void)
{
	glBindVertexArray(mID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindVertexArray(0);
}

} /* namespace OpenGL */
