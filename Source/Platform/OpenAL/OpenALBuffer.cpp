/*
 * AudioBuffer.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#include "OpenALBuffer.h"
#include "OpenALDevice.h"

namespace OpenAL
{

Buffer::Buffer(Device& device):
		Object(device)
{
}

Buffer::~Buffer(void)
{
	alDeleteBuffers(1, &mID);
	mID = 0;
}

void Buffer::Init(void)
{
	alGenBuffers(1, &mID);
	Device::CheckError();
}

} /* namespace Audio */
