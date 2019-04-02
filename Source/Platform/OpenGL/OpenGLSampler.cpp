/*
 * OpenGLSampler.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "OpenGLSampler.h"

namespace OpenGL
{

Sampler::Sampler(void)
{
}

Sampler::~Sampler(void)
{
}

void Sampler::Binding(void)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

} /* namespace OpenGL */
