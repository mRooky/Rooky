/*
 * OpenGLBase.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENGL_OPENGLBASE_H_
#define SOURCE_PLATFORM_OPENGL_OPENGLBASE_H_

#include <GL/glew.h>

namespace OpenGL
{

class Base
{
public:
	Base(void);
	virtual ~Base(void);

public:
	inline GLenum GetResult(void) const { return mResult; }

public:
	static const char* GetResultName(GLenum result);

protected:
	GLenum mResult = ~0u;
};

} /* namespace OpenGL */

#endif /* SOURCE_PLATFORM_OPENGL_OPENGLBASE_H_ */
