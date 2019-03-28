/*
 * Listener.h
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_AUDIO_AUDIOLISTENER_H_
#define SOURCE_CORE_AUDIO_AUDIOLISTENER_H_

#include "AudioObject.h"

namespace Audio
{

class Listener: public Object
{
public:
	explicit Listener(Device& device);
	virtual ~Listener(void) override;
};

} /* namespace Audio */

#endif /* SOURCE_CORE_AUDIO_AUDIOLISTENER_H_ */
