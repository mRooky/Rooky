/*
 * OpenGLContext.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENGL_OPENGLCONTEXT_H_
#define SOURCE_PLATFORM_OPENGL_OPENGLCONTEXT_H_

#include "OpenGLBase.h"

namespace OpenGL
{

class Context : public Base
{
public:
	Context(void);
	virtual ~Context(void);

public:
	void Create(void);
};

} /* namespace OpenGL */

#endif /* SOURCE_PLATFORM_OPENGL_OPENGLCONTEXT_H_ */
