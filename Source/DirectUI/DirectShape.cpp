/*
 * DirectShape.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#include "DirectShape.h"
#include <cassert>

namespace Direct
{

Shape::Shape(Shape* parent)
{
	mParent = parent;
	assert(mPainter == nullptr);
}

Shape::~Shape(void)
{
	mPainter = nullptr;
}

Vector2I Shape::GetOffset(void) const
{
	Vector2I offset = {};
	assert(false);
	return offset;
}

} /* namespace Direct */
