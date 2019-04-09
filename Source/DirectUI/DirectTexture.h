/*
 * DirectTexture.h
 *
 *  Created on: Nov 5, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTTEXTURE_H_
#define DIRECTUI_DIRECTTEXTURE_H_

#include "DirectTarget.h"

namespace Direct
{

class Texture : public Target
{
public:
	Texture(void);
	virtual ~Texture(void) override;

public:
	void Create(const char* file);

protected:
	uint8_t* mBuffer = nullptr;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTTEXTURE_H_ */
