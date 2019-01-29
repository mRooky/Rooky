/*
 * IOKeyboard.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_PLATFORM_PLATFORMKEYBOARD_H_
#define SOURCE_CORE_PLATFORM_PLATFORMKEYBOARD_H_

#include "PlatformInput.h"

namespace Platform
{

class Keyboard : public Input
{
public:
	Keyboard(void);
	virtual ~Keyboard(void) override;
};

} /* namespace IO */

#endif /* SOURCE_CORE_PLATFORM_PLATFORMKEYBOARD_H_ */
