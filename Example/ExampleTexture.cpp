/*
 * ExampleTexture.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#include "ExampleTexture.h"
#include <iostream>

#include <gli/gli.hpp>

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
	gli::texture2d tex(gli::load(file));
	if (!tex.empty())
	{
		uint32_t levels = tex.levels();
		std::cout << "Levels " << levels << std::endl;
		if (levels > 0)
		{
			for (uint32_t index = 0; index < levels; ++index)
			{
				std::cout << "Width " << tex[index].extent().x << std::endl;
				std::cout << "Height " << tex[index].extent().y << std::endl;
				std::cout << "Size " << tex[index].size() << std::endl;
			}
		}
	}
}

} /* namespace Example */
