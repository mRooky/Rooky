/*
 * CoreObject.h
 *
 *  Created on: Feb 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREINTERFACE_H_
#define SOURCE_CORE_COREINTERFACE_H_

#include "CoreBase.h"

namespace Core
{
class System;
class Interface : public Base
{
public:
	explicit Interface(System* system);
	virtual ~Interface(void) override;

public:
	inline System* GetSystem(void) const { return mSystem; }

protected:
	System* mSystem = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREINTERFACE_H_ */
