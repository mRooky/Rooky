/*
 * PlatformInput.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_PLATFORM_PLATFORMINPUT_H_
#define SOURCE_CORE_PLATFORM_PLATFORMINPUT_H_

#include "PlatformEvent.h"
#include <vector>

namespace Platform
{
class Input
{
protected:
	Input(void);
	virtual ~Input(void);

public:
	inline size_t GetEventCount(void) const { return mEvents.size(); }

protected:
	std::vector<Event> mEvents;
};

} /* namespace Platform */

#endif /* SOURCE_CORE_PLATFORM_PLATFORMINPUT_H_ */
