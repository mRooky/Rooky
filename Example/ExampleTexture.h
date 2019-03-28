/*
 * ExampleTexture.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef EXAMPLE_EXAMPLETEXTURE_H_
#define EXAMPLE_EXAMPLETEXTURE_H_

#include "ExampleBuffer.h"

#include "CoreTexture.h"

namespace Example
{

class Texture: public Buffer
{
public:
	Texture(void);
	virtual ~Texture(void) override;

public:
	virtual void Initialize(void) override;

public:
	virtual void CreateTexture(const char* file);
	virtual void CreateShader(void);
	virtual void CreatePipeline(void);

protected:
	Core::Texture* mTexture = nullptr;
};

} /* namespace Example */

#endif /* EXAMPLE_EXAMPLETEXTURE_H_ */
