/*
 * ExampleTexture.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "ExampleTexture.h"
#include <iostream>

namespace Example
{

Texture::Texture(void)
{
}

Texture::~Texture(void)
{
}

void Texture::Initialize(void)
{
	Buffer::Initialize();
	CreateTexture("Resource/vulkan.png");
}

void Texture::CreateTexture(const char* file)
{

}

} /* namespace Example */
