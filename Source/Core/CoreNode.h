/*
 * CoreNode.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORENODE_H_
#define SOURCE_CORE_CORENODE_H_

#include "CoreBase.h"

namespace Core
{

class Node: public Base
{
public:
	Node(void);
	virtual ~Node(void) override;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORENODE_H_ */
