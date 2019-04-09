/*
 * DirectContainer.cpp
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#include "DirectContainer.h"
#include <algorithm>
#include <cassert>

namespace Direct
{

Container::Container(Widget* parent):
		Control(parent)
{
}

Container::~Container(void)
{
	mChildren.clear();
}

void Container::Append(Widget* widget)
{
	assert(widget != nullptr);
	Widget* parent = widget->GetParent();
	if (parent != this)
	{
		widget->SetParent(this);
		mChildren.push_back(widget);
	}
	else
	{
		assert(false);
	}
}

void Container::Remove(Widget* widget)
{
	assert(widget != nullptr);
	Widget* parent = widget->GetParent();
	if (parent == this)
	{
		auto iterator = std::find(mChildren.begin(), mChildren.end(), widget);
		if (iterator != mChildren.end())
		{
			mChildren.erase(iterator);
		}
	}
	else
	{
		assert(false);
	}
}

} /* namespace Direct */
