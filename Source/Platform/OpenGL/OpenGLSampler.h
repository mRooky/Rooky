/*
 * OpenGLSampler.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENGL_OPENGLSAMPLER_H_
#define SOURCE_PLATFORM_OPENGL_OPENGLSAMPLER_H_

#include "OpenGLBase.h"

namespace OpenGL
{

class Sampler : public Base
{
public:
	Sampler(void);
	virtual ~Sampler(void);

public:
	void Binding(void);
};

} /* namespace OpenGL */

#endif /* SOURCE_PLATFORM_OPENGL_OPENGLSAMPLER_H_ */
