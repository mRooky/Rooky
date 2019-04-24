/*
 * AudioBuffer.h
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENAL_OPENALBUFFER_H_
#define SOURCE_PLATFORM_OPENAL_OPENALBUFFER_H_

#include "OpenALObject.h"
#include <cstdint>

namespace OpenAL
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

#endif /* SOURCE_PLATFORM_OPENAL_OPENALBUFFER_H_ */
