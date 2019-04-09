/*
 * CoreNode.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "CoreNode.h"
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

void Node::AppendChild(Node* node)
{
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
