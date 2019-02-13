/*
 * CoreSystem.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESYSTEM_H_
#define SOURCE_CORE_CORESYSTEM_H_

#include "RenderClasses.h"

namespace Core
{

class System
{
public:
	System(void);
	virtual ~System(void);

public:
	void Create(void);

public:
	inline Render::Context* GetContext(void) const { return mContext; }

protected:
	Render::Context* mContext = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESYSTEM_H_ */
