/*
 * CoreStream.cpp
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#include "CoreStream.h"

namespace Core
{

Stream::Stream(void)
{
	mBuffers.fill(nullptr);
}

Stream::~Stream(void)
{
	FreeAllBuffer();
}

void* Stream::GetBuffer(StreamType type)
{
	uint32_t index = static_cast<uint32_t>(type);
	return mBuffers.at(index);
}

void* Stream::Allocate(StreamType type, size_t size, bool discard)
{
	if (discard)
	{
		FreeBuffer(type);
	}
	uint8_t* buffer = new uint8_t[size];
	uint32_t index = static_cast<uint32_t>(type);
	mBuffers.at(index) = buffer;
	return buffer;
}

void Stream::FreeAllBuffer(void)
{
	for (uint32_t index = 0; index < STREAM_TYPE_COUNT; ++index)
	{
		auto type = static_cast<StreamType>(index);
		FreeBuffer(type);
	}
}

void Stream::FreeBuffer(StreamType type)
{
	uint32_t index = static_cast<uint32_t>(type);
	uint8_t* buffer = mBuffers.at(index);
	delete[] buffer;
	mBuffers.at(index) = nullptr;
}

} /* namespace Core */
