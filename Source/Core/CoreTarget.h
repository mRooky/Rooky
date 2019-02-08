/*
 * CoreTarget.h
 *
 *  Created on: Feb 8, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETARGET_H_
#define SOURCE_CORE_CORETARGET_H_

#include "RenderClasses.h"

namespace Core
{

class Target
{
public:
	Target(void);
	virtual ~Target(void);

public:
	inline Render::Image* GetImage(void) const { return mImage; }

protected:
	Render::Image* mImage = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETARGET_H_ */
