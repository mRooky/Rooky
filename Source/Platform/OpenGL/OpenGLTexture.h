/*
 * OpenGLTexture.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENGL_OPENGLTEXTURE_H_
#define SOURCE_PLATFORM_OPENGL_OPENGLTEXTURE_H_

#include "OpenGLObject.h"

namespace OpenGL
{

class Texture: public Object
{
public:
	Texture(void);
	virtual ~Texture(void) override;

public:
	void Create(int32_t width, int32_t height, const void* src);
};

} /* namespace OpenGL */

#endif /* SOURCE_PLATFORM_OPENGL_OPENGLTEXTURE_H_ */
