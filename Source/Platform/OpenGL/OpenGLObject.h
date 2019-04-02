/*
 * OpenGLObject.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENGL_OPENGLOBJECT_H_
#define SOURCE_PLATFORM_OPENGL_OPENGLOBJECT_H_

#include "OpenGLBase.h"

namespace OpenGL
{

class Object : public Base
{
public:
	Object(void);
	virtual ~Object(void);

public:
	inline GLuint GetID(void) const { return mID; }

protected:
	GLuint mID = 0;
};

} /* namespace OpenGL */

#endif /* SOURCE_PLATFORM_OPENGL_OPENGLOBJECT_H_ */
