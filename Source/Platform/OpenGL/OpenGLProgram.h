/*
 * OpenGLProgram.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENGL_OPENGLPROGRAM_H_
#define SOURCE_PLATFORM_OPENGL_OPENGLPROGRAM_H_

#include "OpenGLObject.h"

namespace OpenGL
{
class Shader;
class Program: public Object
{
public:
	Program(void);
	virtual ~Program(void) override;

public:
	void Attach(const Shader* shader);

public:
	inline void Binding(void) { glUseProgram(mID); }

public:
	inline GLuint GetLocation(const char* name) const { return glGetUniformLocation(mID, name); }

public:
	void SetInt(const char* name, int value) const;
	void SetBool(const char* name, bool value) const;
	void SetVec2(const char* name, const float * value) const;
	void SetVec2(const char* name, float x, float y) const;
	void SetVec3(const char* name, const float * value) const;
	void SetVec3(const char* name, float x, float y, float z) const;
	void SetVec4(const char* name, const float * value) const;
	void SetVec4(const char* name, float x, float y, float z, float w);
	void SetMat2(const char* name, const float * value) const;
	void SetMat3(const char* name, const float * value) const;
	void SetMat4(const char* name, const float * value) const;
	void SetFloat(const char* name, float value) const;
};

} /* namespace OpenGL */

#endif /* SOURCE_PLATFORM_OPENGL_OPENGLPROGRAM_H_ */
