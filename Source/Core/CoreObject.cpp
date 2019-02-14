/*
 * CoreObject.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#include "CoreObject.h"

#include <cassert>

namespace Core
{

Object::Object(System* system):
		mSystem(system)
{
	assert(system != nullptr);
}

Object::~Object(void)
{
	mSystem = nullptr;
}

} /* namespace Core */
