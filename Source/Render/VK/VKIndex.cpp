/*
 * VKIndex.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKIndex.h"
#include "VKContext.h"

#include <cassert>

namespace VK
{

Index::Index(Context* context):
		Render::Index(context)
{
}

Index::~Index(void)
{
}

VkIndexType Index::ConvertType(const Render::Index::Type& type)
{
	switch(type)
	{
	case Render::Index::Type::UINT16:
		return VK_INDEX_TYPE_UINT16;
	case Render::Index::Type::UINT32:
		return VK_INDEX_TYPE_UINT32;
	default:
		assert(false);
		return VK_INDEX_TYPE_MAX_ENUM;
	}
}

} /* namespace VK */
