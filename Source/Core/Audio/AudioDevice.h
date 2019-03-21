/*
 * AudioDevice.h
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_AUDIO_AUDIODEVICE_H_
#define SOURCE_CORE_AUDIO_AUDIODEVICE_H_

#include <AL/al.h>
#include <AL/alc.h>
#include <vector>

namespace Audio
{
class Sound;
class Device
{
public:
	Device(void);
	virtual ~Device(void);

public:
	void Init(void);

public:
	static bool CheckError(void);
	static const char* ErrorString(ALCenum code);

protected:
	void OpenDevice(void);
	void CreateContext(void);

protected:
	ALCdevice* mDevice = nullptr;
	ALCcontext* mContext = nullptr;

protected:
	std::vector<Sound*> mSounds;
};

} /* namespace Audio */

#endif /* SOURCE_CORE_AUDIO_AUDIODEVICE_H_ */
