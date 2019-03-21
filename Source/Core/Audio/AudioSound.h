/*
 * AudioSound.h
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_AUDIO_AUDIOSOUND_H_
#define SOURCE_CORE_AUDIO_AUDIOSOUND_H_

namespace Audio
{
class Device;
class Buffer;
class Sound
{
public:
	explicit Sound(Device& parent);
	virtual ~Sound(void);

private:
	Device& m_parent;

private:
	Buffer* m_buffer = nullptr;
};

} /* namespace Audio */

#endif /* SOURCE_CORE_AUDIO_AUDIOSOUND_H_ */
