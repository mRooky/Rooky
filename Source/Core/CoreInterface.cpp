/*
 * CoreObject.cpp
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#include "CoreInterface.h"
#include <cassert>

namespace Core
{

Interface::Interface(System* system):
		mSystem(system)
{
	assert(system != nullptr);
}

Interface::~Interface(void)
{
	mSystem = nullptr;
}

} /* namespace Core */
