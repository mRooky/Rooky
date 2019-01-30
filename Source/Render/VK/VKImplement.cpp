/*
 * VKImplement.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "VKContext.h"
#include <cassert>

namespace Render
{
	Context* CreateContext(void)
	{
		return new VK::Context;
	}

	void DestroyContext(Context* context)
	{
		assert(context != nullptr);
		delete context;
	}
}


