/*
 * CoreDeferred.h
 *
 *  Created on: Apr 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_POLICY_COREDEFERRED_H_
#define SOURCE_CORE_POLICY_COREDEFERRED_H_

#include "CorePolicy.h"

namespace Core
{

class Deferred: public Policy
{
public:
	Deferred(System* system);
	virtual ~Deferred(void) override;
};

} /* namespace Core */

#endif /* SOURCE_CORE_POLICY_COREDEFERRED_H_ */
