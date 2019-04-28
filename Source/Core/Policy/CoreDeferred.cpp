/*
 * CoreDeferred.cpp
 *
 *  Created on: Apr 25, 2019
 *      Author: rookyma
 */

#include "CoreDeferred.h"

namespace Core
{

Deferred::Deferred(void):
		Policy(PolicyType::FORWARD)
{
}

Deferred::~Deferred(void)
{
}

} /* namespace Core */
