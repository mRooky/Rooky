/*
 * OpenGLBuffer.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENGL_OPENGLBUFFER_H_
#define SOURCE_PLATFORM_OPENGL_OPENGLBUFFER_H_

#include "OpenGLObject.h"

namespace OpenGL
{

class Buffer: public Object
{
public:
	Buffer(void);
	virtual ~Buffer(void);

public:
	void Create(size_t size, const void* src);
};

} /* namespace OpenGL */

#endif /* SOURCE_PLATFORM_OPENGL_OPENGLBUFFER_H_ */
