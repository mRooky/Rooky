/*
 * OpenGLProgram.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#include "OpenGLProgram.h"
#include "OpenGLShader.h"

namespace OpenGL
{

Program::Program(void)
{
	mID = glCreateProgram();
}

Program::~Program(void)
{
	glDeleteProgram(mID);
}

void Program::Attach(const Shader* shader)
{
	GLuint shader_id = shader->GetID();
	glAttachShader(mID, shader_id);
	glLinkProgram(mID);
	Shader::CheckCompileErrors(mID, "PROGRAM");
}

void Program::SetBool(const char* name, bool value) const
{
	GLuint location = GetLocation(name);
	glUniform1i(location, (int) value);
}

void Program::SetInt(const char* name, int value) const
{
	GLuint location = GetLocation(name);
	glUniform1i(location, value);
}

void Program::SetFloat(const char* name, float value) const
{
	GLuint location = GetLocation(name);
	glUniform1f(location, value);
}

void Program::SetVec2(const char* name, const float * value) const
{
	GLuint location = GetLocation(name);
	glUniform2fv(location, 1, value);
}

void Program::SetVec2(const char* name, float x, float y) const
{
	GLuint location = GetLocation(name);
	glUniform2f(location, x, y);
}

void Program::SetVec3(const char* name, const float * value) const
{
	GLuint location = GetLocation(name);
	glUniform3fv(location, 1, value);
}

void Program::SetVec3(const char* name, float x, float y, float z) const
{
	GLuint location = GetLocation(name);
	glUniform3f(location, x, y, z);
}

void Program::SetVec4(const char* name, const float * value) const
{
	GLuint location = GetLocation(name);
	glUniform4fv(location, 1, value);
}

void Program::SetVec4(const char* name, float x, float y, float z, float w)
{
	GLuint location = GetLocation(name);
	glUniform4f(location, x, y, z, w);
}

void Program::SetMat2(const char* name, const float * value) const
{
	GLuint location = GetLocation(name);
	glUniformMatrix2fv(location, 1, GL_FALSE, value);
}

void Program::SetMat3(const char* name, const float * value) const
{
	GLuint location = GetLocation(name);
	glUniformMatrix3fv(location, 1, GL_FALSE, value);
}

void Program::SetMat4(const char* name, const float * value) const
{
	GLuint location = GetLocation(name);
	glUniformMatrix4fv(location, 1, GL_FALSE, value);
}

} /* namespace OpenGL */
