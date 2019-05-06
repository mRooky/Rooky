/*
 * CoreNode.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORENODE_H_
#define SOURCE_CORE_CORENODE_H_

#include "CoreMovable.h"
#include <vector>

namespace Core
{
class Object;
class Node: public Movable
{
public:
	Node(Node* parent = nullptr);
	virtual ~Node(void) override;

public:
	void AppendChild(Node* node);

public:
	void AttachObject(Object* object);
	Object* DetachObject(void);

public:
	const Object* GetAttachObject(void) const { return mObject; }

public:
	inline size_t GetChildrenCount(void) const { return mChildren.size(); }
	inline Node* GetChild(size_t index) const { return mChildren.at(index); }

public:
	inline void SetParent(Node* node) { mParent = node; }
	inline Node* GetParent(void) const { return mParent; }

protected:
	Node* mParent = nullptr;
	Object* mObject = nullptr;
	std::vector<Node*> mChildren;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORENODE_H_ */
