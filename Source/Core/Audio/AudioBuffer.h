/*
 * AudioBuffer.h
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_AUDIO_AUDIOBUFFER_H_
#define SOURCE_CORE_AUDIO_AUDIOBUFFER_H_

#include "AudioObject.h"
#include <cstdint>

namespace Audio
{
class Buffer : public Object
{
public:
	explicit Buffer(Device& device);
	virtual ~Buffer(void) override;

public:
	void Init(void);

private:
	ALuint m_format = 0;
	uint32_t m_size = 0;
	uint32_t m_rate = 0;
};

} /* namespace Audio */

#endif /* SOURCE_CORE_AUDIO_AUDIOBUFFER_H_ */
