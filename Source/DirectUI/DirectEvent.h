/*
 * DirectEvent.h
 *
 *  Created on: Nov 25, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTEVENT_H_
#define DIRECTUI_DIRECTEVENT_H_

#include <cstdint>

namespace Direct
{

class Event
{
public:
	enum class Type : uint32_t
	{
		EMPTY_EVENT = 0,
		KEYBOARD_EVENT = 1,
		MOUSE_EVENT = 2,
		UNKNOWN_EVENT = ~0U
	};

public:
	Event(void);
	virtual ~Event(void);

public:
	inline void SetType(Type type) { m_type = type; }
	inline Type GetType(void) const { return m_type; }

private:
	Type m_type = Type::EMPTY_EVENT;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTEVENT_H_ */
