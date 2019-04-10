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
	uint32_t stream_index = GetIndex(type);
	return &mBuffers.at(stream_index);
}

Data* StreamData::Allocate(StreamType type, size_t size)
{
	uint32_t stream_index = GetIndex(type);
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
	uint32_t stream_index = GetIndex(type);
	assert(stream_index < STREAM_TYPE_COUNT);
	mBuffers.at(stream_index).FreeBuffer();
}

} /* namespace Core */
