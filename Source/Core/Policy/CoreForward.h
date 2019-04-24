/*
 * Forward.h
 *
 *  Created on: Apr 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_POLICY_COREFORWARD_H_
#define SOURCE_CORE_POLICY_COREFORWARD_H_

#include "CorePolicy.h"

namespace Core
{

class Forward: public Policy
{
public:
	Forward(void);
	virtual ~Forward(void) override;
};

} /* namespace Core */

#endif /* SOURCE_CORE_POLICY_COREFORWARD_H_ */
