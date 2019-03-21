/*
 * AudioObject.h
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_AUDIO_AUDIOOBJECT_H_
#define SOURCE_CORE_AUDIO_AUDIOOBJECT_H_

#include <AL/al.h>
#include <AL/alc.h>

namespace Audio
{
class Device;
class Object
{
public:
	explicit Object(Device& device);
	virtual ~Object(void);

protected:
	ALuint mID = 0;
	Device& mDevice;
};

} /* namespace Audio */

#endif /* SOURCE_CORE_AUDIO_AUDIOOBJECT_H_ */
