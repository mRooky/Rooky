/*
 * CoreTarget.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#include "CoreTarget.h"
#include <cassert>

namespace Core
{

Target::Target(TextureManager* manager):
		mManager(manager)
{
	assert(mManager != nullptr);
}

Target::~Target(void)
{
	mManager = nullptr;
}

void Target::Create(const Render::ImageLayout& layout)
{

}

} /* namespace Core */
