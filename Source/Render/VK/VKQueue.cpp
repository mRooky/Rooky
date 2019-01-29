/*
 * VKQueue.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKQueue.h"
#include "VKContext.h"

namespace VK
{

Queue::Queue(Context* context):
		Render::Queue(context)
{
}

Queue::~Queue(void)
{
	mQueue = nullptr;
}

} /* namespace VK */
