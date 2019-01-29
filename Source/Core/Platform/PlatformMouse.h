/*
 * IOMouse.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_PLATFORM_PLATFORMMOUSE_H_
#define SOURCE_CORE_PLATFORM_PLATFORMMOUSE_H_

#include "PlatformInput.h"

namespace Platform
{

class Mouse : public Input
{
public:
	Mouse(void);
	virtual ~Mouse(void) override;
};

} /* namespace IO */

#endif /* SOURCE_CORE_PLATFORM_PLATFORMMOUSE_H_ */
