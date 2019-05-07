/*
 * CoreShaderResource.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#include "CoreShaderResource.h"

namespace Core
{

ShaderResource::ShaderResource(void)
{
}

ShaderResource::~ShaderResource(void)
{
	mShader = nullptr;
	mBindings.clear();
}

} /* namespace Core */
