/*
 * Listener.h
 *
 *  Created on: Mar 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_PLATFORM_OPENAL_OPENALLISTENER_H_
#define SOURCE_PLATFORM_OPENAL_OPENALLISTENER_H_

#include "OpenALObject.h"

namespace OpenAL
{

class Listener: public Object
{
public:
	explicit Listener(Device& device);
	virtual ~Listener(void) override;
};

} /* namespace Audio */

#endif /* SOURCE_PLATFORM_OPENAL_OPENALLISTENER_H_ */
