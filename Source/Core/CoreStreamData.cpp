/*
 * CoreStreamData.cpp
 *
 *  Created on: Apr 10, 2019
 *      Author: rookyma
 */

#include "CoreStreamData.h"
#include <cassert>

namespace Core
{

StreamData::StreamData(void)
{
}

StreamData::~StreamData(void)
{
	FreeAllBuffer();
}

const void* StreamData::GetSemanticBuffer(StreamType type) const
{
	switch(type)
	{
	case StreamType::STREAM_TYPE_POSITION:
		return mStreamPosition.GetDataMemory();
	case StreamType::STREAM_TYPE_COLOR:
		return mStreamColor.GetDataMemory();
	case StreamType::STREAM_TYPE_NORMAL:
		return mStreamNormal.GetDataMemory();
	case StreamType::STREAM_TYPE_TANGENT:
		assert(false);
		return nullptr;
	case StreamType::STREAM_TYPE_TEXCOORD:
		return mStreamCoord.GetDataMemory();
	case StreamType::STREAM_TYPE_WEIGHT:
		assert(false);
		return nullptr;
	default:
		assert(false);
		return nullptr;
	}
}

Data* StreamData::AllocateIndexBuffer(size_t size)
{
	mIndexBuffer.FreeMemory();
	mIndexBuffer.AllocateMemory(size);
	return &mIndexBuffer;
}

void* StreamData::AllocateSemanticBuffer(StreamType type, size_t count)
{
	switch(type)
	{
	case StreamType::STREAM_TYPE_POSITION:
		return mStreamPosition.Create(count);
	case StreamType::STREAM_TYPE_COLOR:
		return mStreamColor.Create(count);
	case StreamType::STREAM_TYPE_NORMAL:
		return mStreamNormal.Create(count);
	case StreamType::STREAM_TYPE_TANGENT:
		assert(false);
		return nullptr;
	case StreamType::STREAM_TYPE_TEXCOORD:
		return mStreamCoord.Create(count);
	case StreamType::STREAM_TYPE_WEIGHT:
		assert(false);
		return nullptr;
	default:
		assert(false);
		return nullptr;
	}
}

void StreamData::FreeAllBuffer(void)
{
	mIndexBuffer.FreeMemory();
	mStreamColor.ClearSemanticData();
	mStreamCoord.ClearSemanticData();
	mStreamNormal.ClearSemanticData();
	mStreamPosition.ClearSemanticData();
}

void StreamData::FreeSemanticBuffer(StreamType type)
{
	switch(type)
	{
	case StreamType::STREAM_TYPE_POSITION:
		mStreamPosition.ClearSemanticData();
		break;
	case StreamType::STREAM_TYPE_COLOR:
		mStreamColor.ClearSemanticData();
		break;
	case StreamType::STREAM_TYPE_NORMAL:
		mStreamNormal.ClearSemanticData();
		break;
	case StreamType::STREAM_TYPE_TANGENT:
		assert(false);
		break;
	case StreamType::STREAM_TYPE_TEXCOORD:
		mStreamCoord.ClearSemanticData();
		break;
	case StreamType::STREAM_TYPE_WEIGHT:
		assert(false);
		break;
	default:
		assert(false);
	}
}

size_t StreamData::GetValidCount(void) const
{
	size_t count = 0;
	count += mStreamColor.IsValid() ? 1 : 0;
	count += mStreamCoord.IsValid() ? 1 : 0;
	count += mStreamNormal.IsValid() ? 1 : 0;
	count += mStreamPosition.IsValid() ? 1 : 0;
	return count;
}

} /* namespace Core */
