/*
 * VKUniform.cpp
 *
 *  Created on: Feb 1, 2019
 *      Author: rookyma
 */

#include "VKUniform.h"
#include "VKBufferManager.h"

namespace VK
{

Uniform::Uniform(BufferManager* manager):
		Render::Uniform(manager)
{
}

Uniform::~Uniform(void)
{
}

} /* namespace VK */
