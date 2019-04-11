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
		return mStreamTexCoord.GetDataMemory();
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
		return mStreamTexCoord.Create(count);
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
	mStreamTexCoord.ClearSemanticData();
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
		mStreamTexCoord.ClearSemanticData();
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
	count += mStreamTexCoord.IsValid() ? 1 : 0;
	count += mStreamNormal.IsValid() ? 1 : 0;
	count += mStreamPosition.IsValid() ? 1 : 0;
	return count;
}

size_t StreamData::GetSemanticStride(void) const
{
	size_t stride = 0;
	stride += mStreamColor.IsValid() ? StreamColor::GetSemanticSize() : 0;
	stride += mStreamTexCoord.IsValid() ? StreamTexCoord::GetSemanticSize() : 0;
	stride += mStreamNormal.IsValid() ? StreamNormal::GetSemanticSize() : 0;
	stride += mStreamPosition.IsValid() ? StreamPosition::GetSemanticSize() : 0;
	return stride;
}

void StreamData::ReadSemanticData(void* dst, size_t index)
{
	uint8_t* destination = reinterpret_cast<uint8_t*>(dst);
	destination += mStreamPosition.WriteTo(destination, index);
	destination += mStreamColor.WriteTo(destination, index);
	destination += mStreamNormal.WriteTo(destination, index);
	destination += mStreamTexCoord.WriteTo(destination, index);
}

} /* namespace Core */
