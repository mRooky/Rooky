/*
 * RenderIndex.cpp
 *
 *  Created on: Jan 23, 2019
 *      Author: rookyma
 */

#include "RenderIndex.h"
#include <cassert>

namespace Render
{

Index::Index(BufferManager* manager):
		Buffer(manager)
{
}

Index::~Index(void)
{
}

size_t Index::GetTypeSize(const Type& type)
{
	switch(type)
	{
	case Type::UINT16:
		return 2;
	case Type::UINT32:
		return 4;
	default:
		assert(false);
		return 0;
	}
}

} /* namespace Render */
