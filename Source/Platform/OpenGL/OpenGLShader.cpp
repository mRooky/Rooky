/*
 * OpenGLShader.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "OpenGLShader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace OpenGL
{

Shader::Shader(GLuint type) :
		mType(type)
{
	mID = glCreateShader(type);
	mID = glCreateShader(GL_VERTEX_SHADER);
}

Shader::~Shader(void)
{
	glDeleteShader(mID);
}

void Shader::Create(const char* file)
{
	std::ifstream shader_file;
	shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	shader_file.open(file);
	std::stringstream shader_stream;
	shader_stream << shader_file.rdbuf();
	shader_file.close();
	std::string shader_code = shader_stream.str();
	const char* code = shader_code.c_str();
	glShaderSource(mID, 1, &code, NULL);
	glCompileShader(mID);
	Shader::CheckCompileErrors(mID, Shader::GetTypeName(mType));
}

const char* Shader::GetTypeName(GLuint type)
{
	switch(type)
	{
	case GL_VERTEX_SHADER:
		return "VERTEX";
	case GL_FRAGMENT_SHADER:
		return "FRAGMENT";
	default:
		return "PROGRAM";
	}
}

void Shader::CheckCompileErrors(GLuint shader, const char* type)
{
	GLint success;
	GLchar info_log[1024];
	std::string type_string(type);
	if (type_string != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, info_log);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << std::endl;
			std::cout << info_log << std::endl;
			std::cout << " -- --------------------------------------------------- -- " << std::endl;
			std::cout << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, info_log);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << std::endl;
			std::cout << info_log << std::endl;
			std::cout << " -- --------------------------------------------------- -- " << std::endl;
			std::cout << std::endl;
		}
	}
}

} /* namespace OpenGL */
