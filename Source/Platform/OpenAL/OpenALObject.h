/*
 * AudioObject.h
 *
 *  Created on: Mar 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENAL_OPENALOBJECT_H_
#define SOURCE_PLATFORM_OPENAL_OPENALOBJECT_H_

#include <AL/al.h>
#include <AL/alc.h>

namespace OpenAL
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

#endif /* SOURCE_PLATFORM_OPENAL_OPENALOBJECT_H_ */
