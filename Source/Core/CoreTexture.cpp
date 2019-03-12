/*
 * CoreTexture.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreTexture.h"

namespace Core
{

Texture::Texture(System* system):
		Target(system)
{
}

Texture::~Texture(void)
{
	mSampler = nullptr;
}

void Texture::Create(const char* file)
{

}

} /* namespace Core */
