/*
 * AudioBuffer.h
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_AUDIO_AUDIOBUFFER_H_
#define SOURCE_CORE_AUDIO_AUDIOBUFFER_H_

#include <AL/al.h>
#include <AL/alc.h>
#include <cstdint>

namespace Audio
{
class Device;
class Buffer
{
public:
	explicit Buffer(Device& parent);
	virtual ~Buffer(void);

private:
	Device& m_parent;

private:
	ALuint m_buffer = 0;
	ALuint m_format = 0;
	uint32_t m_size = 0;
	uint32_t m_rate = 0;
};

} /* namespace Audio */

#endif /* SOURCE_CORE_AUDIO_AUDIOBUFFER_H_ */
