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

Data* StreamData::GetBuffer(StreamType type)
{
	uint32_t stream_index = CastStream(type);
	auto& data = mBuffers.at(stream_index);
	return data.IsValid() ? &mBuffers.at(stream_index) : nullptr;
}

Data* StreamData::AllocateBuffer(StreamType type, size_t size)
{
	uint32_t stream_index = CastStream(type);
	mBuffers.at(stream_index).FreeBuffer();
	mBuffers.at(stream_index).Allocate(size);
	return &mBuffers.at(stream_index);
}

void StreamData::FreeAllBuffer(void)
{
	for (auto data : mBuffers)
	{
		data.FreeBuffer();
	}
}

void StreamData::FreeBuffer(StreamType type)
{
	uint32_t stream_index = CastStream(type);
	assert(stream_index < STREAM_TYPE_COUNT);
	mBuffers.at(stream_index).FreeBuffer();
}

} /* namespace Core */
