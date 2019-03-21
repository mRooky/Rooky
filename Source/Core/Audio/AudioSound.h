/*
 * AudioSound.h
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_AUDIO_AUDIOSOUND_H_
#define SOURCE_CORE_AUDIO_AUDIOSOUND_H_

#include "AudioObject.h"

namespace Audio
{
class Buffer;
class Sound : public Object
{
public:
	explicit Sound(Device& device);
	virtual ~Sound(void) override;

public:
	void Init(void);
	void Update(void);
	void Play(void);
	void Stop(void);
	void Pause(void);

protected:
	Buffer* mBuffer = nullptr;
};

} /* namespace Audio */

#endif /* SOURCE_CORE_AUDIO_AUDIOSOUND_H_ */
