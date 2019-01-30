/*
 * VKIndex.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKIndex.h"
#include "VKContext.h"

#include "VKHardwareBuffer.h"

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

void Index::Initialize(Render::Index::Type type, size_t count)
{
	assert(count > 0);
	assert(mHardwareBuffer == nullptr);
	mType = type;
	mCount = count;
	VkDeviceSize size = Render::Index::GetTypeSize(mType) * mCount;
	VkBufferUsageFlags usage = VK_BUFFER_USAGE_INDEX_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
	mHardwareBuffer = new HardwareBuffer(static_cast<Context*>(mContext));
	mHardwareBuffer->Initialize(size, usage);
	//VK internal type
	mVKType = ConvertType(type);
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

Render::Index::Type Index::ConvertType(const VkIndexType& type)
{
	switch(type)
	{
	case VK_INDEX_TYPE_UINT16:
		return Render::Index::Type::UINT16;
	case VK_INDEX_TYPE_UINT32:
		return Render::Index::Type::UINT32;
	default:
		assert(false);
		return Render::Index::Type::UNKNOWN;
	}
}

} /* namespace VK */
