/*
 * Buffer.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include <RenderBuffer.h>

namespace Render
{

Buffer::Buffer(Context* context):
		Memory(context)
{
	mType = ResourceType::RESOURCE_TYPE_BUFFER;
}

Buffer::~Buffer(void)
{
}

} /* namespace Render */
