/*
 * CoreMovable.h
 *
 *  Created on: Apr 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMOVABLE_H_
#define SOURCE_CORE_COREMOVABLE_H_

#include "MathTransform.h"
#include "CoreBase.h"

namespace Core
{

class Movable: public Base
{
public:
	Movable(void);
	virtual ~Movable(void) override;

public:
	inline Math::Transform* GetTransform(void) { return &mTransform; }

protected:
	Math::Transform mTransform = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMOVABLE_H_ */
