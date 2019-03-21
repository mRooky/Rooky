/*
 * AudioDevice.cpp
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#include "AudioDevice.h"
#include "AudioSound.h"
#include <cassert>
#include <iostream>

namespace Audio
{

Device::Device(void)
{
}

Device::~Device(void)
{
	alcProcessContext(mContext);

	for (auto sound : mSounds)
	{
		delete sound;
	}
	mSounds.clear();

	alcMakeContextCurrent(nullptr);
	alcDestroyContext(mContext);
	mContext = nullptr;
	alcCloseDevice(mDevice);
	mDevice = nullptr;
}

void Device::Init(void)
{
	OpenDevice();
	CreateContext();
}

void Device::OpenDevice(void)
{
	mDevice = alcOpenDevice(nullptr);
	assert(mDevice != nullptr);
	const ALCchar* device_name = alcGetString(mDevice, ALC_DEVICE_SPECIFIER);
	std::cout << "OpenAL Device Name : " << device_name << std::endl;
}

void Device::CreateContext(void)
{
	assert(mDevice != nullptr);
	mContext = alcCreateContext(mDevice, nullptr);
	bool error = Device::CheckError();
	assert(mContext != nullptr && error == false);
	alcMakeContextCurrent(mContext);
	error = Device::CheckError();
	if (!error)
	{
		std::cout << "OpenAL Device Vendor : " << alcGetString(mDevice, AL_VENDOR) << std::endl;
		std::cout << "OpenAL Device Version : " << alcGetString(mDevice, AL_VERSION) << std::endl;
		std::cout << "OpenAL Device Renderer : " << alcGetString(mDevice, AL_RENDERER) << std::endl;
		std::cout << "OpenAL Device Extensions : " << alcGetString(mDevice, AL_EXTENSIONS) << std::endl;
	}
}

bool Device::CheckError(void)
{
	ALCenum code = alGetError();
	if(!code == AL_NO_ERROR)
	{
		const char* str = Device::ErrorString(code);
		std::cout << "OpenAL Error : " <<str << std::endl;
		return false;
	}
	return true;
}

const char* Device::ErrorString(ALCenum code)
{
#define AL_CASE(x) case x : return #x
	switch(code)
	{
	AL_CASE(AL_INVALID_NAME);
	AL_CASE(AL_INVALID_VALUE);
	AL_CASE(AL_OUT_OF_MEMORY);
	AL_CASE(AL_INVALID_ENUM);
	AL_CASE(AL_INVALID_OPERATION);
	default:
		return "Unknown";
	}
#undef AL_CASE
}

} /* namespace Audio */
