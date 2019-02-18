/*
 * PluginTexture.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: rookyma
 */

#include "PluginTexture.h"
#include <cassert>

namespace Plugin
{

Texture::Texture(void)
{
}

Texture::~Texture(void)
{
	delete[] m_data;
	m_data = nullptr;
}

uint8_t* Texture::Allocate(size_t size)
{
	assert(m_data == nullptr);
	m_data = new uint8_t[size];
	return m_data;
}

} /* namespace Plugin */
