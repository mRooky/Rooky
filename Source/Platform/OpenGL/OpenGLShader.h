/*
 * OpenGLShader.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENGL_OPENGLSHADER_H_
#define SOURCE_PLATFORM_OPENGL_OPENGLSHADER_H_

#include "OpenGLObject.h"

namespace OpenGL
{

class Shader: public Object
{
public:
	explicit Shader(GLuint type);
	virtual ~Shader(void) override;

public:
	void Create(const char* file);

public:
	static const char* GetTypeName(GLuint type);
	static void CheckCompileErrors(GLuint shader, const char* type);

protected:
	GLuint mType = 0;
};

} /* namespace OpenGL */

#endif /* SOURCE_PLATFORM_OPENGL_OPENGLSHADER_H_ */
