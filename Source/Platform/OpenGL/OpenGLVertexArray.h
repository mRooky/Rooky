/*
 * OpenGLVertexArray.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENGL_OPENGLVERTEXARRAY_H_
#define SOURCE_PLATFORM_OPENGL_OPENGLVERTEXARRAY_H_

#include "OpenGLObject.h"

namespace OpenGL
{

class VertexArray: public Object
{
public:
	VertexArray(void);
	virtual ~VertexArray(void);

public:
	void Binding(void);
};

} /* namespace OpenGL */

#endif /* SOURCE_PLATFORM_OPENGL_OPENGLVERTEXARRAY_H_ */
