/*
 * CoreObject.h
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREOBJECT_H_
#define SOURCE_CORE_COREOBJECT_H_

#include "CoreBase.h"

namespace Core
{
class System;
class Object : public Base
{
public:
	explicit Object(System* system);
	virtual ~Object(void) override;

public:
	inline System* GetSystem(void) const { return mSystem; }

protected:
	System* mSystem = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREOBJECT_H_ */
