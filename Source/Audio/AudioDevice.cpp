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
	std::cout << "OpenAL Device Name : " << alcGetString(mDevice, ALC_DEVICE_SPECIFIER) << std::endl;
	std::cout << "OpenAL Device Extensions : " << alcGetString(mDevice, ALC_EXTENSIONS) << std::endl;
}

void Device::CreateContext(void)
{
	assert(mDevice != nullptr);
	mContext = alcCreateContext(mDevice, nullptr);
	if (mContext != nullptr)
	{
		ALCboolean error = alcMakeContextCurrent(mContext);
		if (error == AL_TRUE)
		{
			std::cout << "OpenAL Device Vendor : " << alGetString(AL_VENDOR) << std::endl;
			std::cout << "OpenAL Device Version : " << alGetString(AL_VERSION) << std::endl;
			std::cout << "OpenAL Device Renderer : " << alGetString(AL_RENDERER) << std::endl;
			std::cout << "OpenAL Device Extensions : " << alGetString(AL_EXTENSIONS) << std::endl;
			return;
		}
	}
	Device::CheckError();
	assert(false);
}

void Device::CheckError(void)
{
	ALCenum code = alGetError();
	std::cout << "OpenAL Error : " << Device::ErrorString(code) << std::endl;
	assert(code == AL_NO_ERROR);
}

void Device::MakeCurrent(void)
{
	assert(mContext != nullptr);
	ALCboolean error = alcMakeContextCurrent(mContext);
	assert(error == AL_TRUE);
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
