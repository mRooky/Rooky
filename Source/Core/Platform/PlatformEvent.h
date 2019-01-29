/*
 * PlatformEvent.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_PLATFORM_PLATFORMEVENT_H_
#define SOURCE_CORE_PLATFORM_PLATFORMEVENT_H_

#include <cstdint>

namespace Platform
{

class Event
{
public:
	enum class Type : uint32_t
	{
		MOUSE,
		KEYBOARD,
		FOCUS,
		CUSTOM
	};

public:
	Event(void);
	virtual ~Event(void);

public:
	inline Type GetType(void) const { return mType; }

protected:
	Type mType = Type::CUSTOM;
};

} /* namespace Platform */

#endif /* SOURCE_CORE_PLATFORM_PLATFORMEVENT_H_ */
