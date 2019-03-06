/*
 * RenderResourceList.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#include "RenderResourceList.h"
#include <cassert>

namespace Render
{

ResourceList::ResourceList(ResourceLayout* layout):
		mLayout(layout)
{
}

ResourceList::~ResourceList(void)
{
}

} /* namespace Render */
