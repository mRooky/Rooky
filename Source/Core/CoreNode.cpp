/*
 * CoreNode.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "CoreNode.h"
#include "CoreObject.h"
#include "UtilitySearch.h"
#include <algorithm>
#include <cassert>

namespace Core
{

Node::Node(Node* parent):
		mParent(parent)
{
}

Node::~Node(void)
{
}

void Node::AttachObject(Object* object)
{
	assert(object != nullptr);
	assert(object->GetParent() == nullptr);
	assert(mChildren.size() == 0);
	assert(mObject == nullptr);
	mObject = object;
	mObject->SetParent(this);
}

Object* Node::DetachObject(void)
{
	Object* ret = mObject;
	mObject = nullptr;
	ret->SetParent(nullptr);
	return ret;
}

void Node::AppendChild(Node* node)
{
	assert(mObject == nullptr);
	if (nullptr == node->GetParent())
	{
		auto iterator = Utility::Find(mChildren, node);
		if (iterator == mChildren.end())
		{
			node->SetParent(this);
			mChildren.push_back(node);
		}
	}
}

} /* namespace Core */
