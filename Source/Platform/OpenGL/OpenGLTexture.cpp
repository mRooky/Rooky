/*
 * OpenGLTexture.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "OpenGLTexture.h"

namespace OpenGL
{

Texture::Texture(void)
{
	glGenTextures(1, &mID);
	mResult = glGetError();
}

Texture::~Texture(void)
{
	glDeleteTextures(1, &mID);
}

void Texture::Create(int32_t width, int32_t height, const void* src)
{
	glBindTexture(GL_TEXTURE_2D, mID);
	glTexImage2D( GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, src);
	glBindTexture(GL_TEXTURE_2D, 0);
}

} /* namespace OpenGL */
