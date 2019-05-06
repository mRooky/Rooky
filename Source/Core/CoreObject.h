/*
 * CoreObject.h
 *
 *  Created on: May 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREOBJECT_H_
#define SOURCE_CORE_COREOBJECT_H_

#include "CoreBase.h"

namespace Core
{
class Node;
class Thread;
class Object : public Base
{
public:
	Object(void);
	virtual ~Object(void) override;

public:
	virtual void Render(Thread& thread) = 0;

public:
	inline void SetParent(Node* parent) { mParent = parent; }
	inline Node* GetParent(void) const { return mParent; }

private:
	Node* mParent = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREOBJECT_H_ */
