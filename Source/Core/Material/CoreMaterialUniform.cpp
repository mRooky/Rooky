/*
 * CoreMaterialUniform.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#include "CoreMaterialUniform.h"
#include <cstring>

namespace Core
{

MaterialUniform::MaterialUniform(void)
{
	static_assert(sizeof(mBuffer) == 128, __FILE__);
	std::memset(mBuffer.data(), 0u, sizeof(mBuffer));
}

MaterialUniform::~MaterialUniform(void)
{
	mOffset = 0;
	mUniform = nullptr;
}

} /* namespace Core */
