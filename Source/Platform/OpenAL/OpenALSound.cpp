/*
 * AudioSound.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#include "OpenALDevice.h"
#include "OpenALSound.h"
#include <cassert>

namespace OpenAL
{

Sound::Sound(Device& device):
		Object(device)
{
}

Sound::~Sound(void)
{
	mDevice.MakeCurrent();
	alDeleteSources(1, &mID);
	mID = 0;
}

void Sound::Init(void)
{
	mDevice.MakeCurrent();
	alGenSources(1, &mID);
	Device::CheckError();
}

void Sound::Update(void)
{
	mDevice.MakeCurrent();
	assert(false);
}

void Sound::Play(void)
{
	mDevice.MakeCurrent();
	alSourcePlay(mID);
}

void Sound::Stop(void)
{
	mDevice.MakeCurrent();
	alSourceStop(mID);
	alSourcei(mID, AL_BUFFER, 0);
}

void Sound::Pause(void)
{
	mDevice.MakeCurrent();
	alSourcePause(mID);
}

} /* namespace Audio */
