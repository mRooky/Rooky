/*
 * CoreResource.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#include "CoreResource.h"
#include "GHI/GHIResource.h"

namespace Core
{

Resource::Resource(void)
{
}

Resource::~Resource(void)
{
	delete mResource;
	mResource = nullptr;
}

} /* namespace Core */
