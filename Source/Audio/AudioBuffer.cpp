/*
 * AudioBuffer.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#include "AudioBuffer.h"
#include "AudioDevice.h"

namespace Audio
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
