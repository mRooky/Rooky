/*
 * Vertex.cpp
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#include "VKVertex.h"
#include "VKContext.h"
#include "VKHardwareBuffer.h"
#include "VKBufferManager.h"

#include "RenderDeclaration.h"

#include <cassert>

namespace VK
{

Vertex::Vertex(BufferManager* manager):
		Render::Vertex(manager)
{
}

Vertex::~Vertex(void)
{
	delete mHardwareBuffer;
	mHardwareBuffer = nullptr;
}

void Vertex::Initialize(Render::Declaration* decl, size_t count)
{
	assert(count > 0);
	assert(decl == nullptr);
	assert(mHardwareBuffer == nullptr);
	mDeclaration = decl;
	mCount = count;
	mStride = mDeclaration->GetStride();
	VkBufferUsageFlags usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
	uint32_t size = mStride * mCount;

	Render::Context* context = mManager->GetContext();
	Context* vk_context = static_cast<Context*>(context);
	mHardwareBuffer = new HardwareBuffer(vk_context);
	mHardwareBuffer->Initialize(size, usage);
}

} /* namespace VK */
