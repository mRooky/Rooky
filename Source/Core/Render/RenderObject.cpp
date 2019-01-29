/*
 * RenderObject.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "RenderObject.h"
#include <cassert>

namespace Render
{

Object::Object(Context* context):
		mContext(context)
{
	assert(mContext != nullptr);
}

Object::~Object(void)
{
	mContext = nullptr;
}

} /* namespace Render */
