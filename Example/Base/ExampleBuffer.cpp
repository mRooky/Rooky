/*
 * ExampleBuffer.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "ExampleBuffer.h"

#include "CoreBufferManager.h"
#include "CoreIndex.h"
#include "CoreVertex.h"
#include "CoreUniform.h"

#include <cassert>

namespace Example
{

Buffer::Buffer(void)
{
}

Buffer::~Buffer(void)
{
	mIndex = nullptr;
	mVertex = nullptr;
	mUniform = nullptr;
}

void Buffer::CreateBuffer(void)
{
	assert(mSystem != nullptr);
	auto manager = mSystem->GetBufferManager();

	mIndex = manager->CreateIndex();
	mIndex->Create(Render::IndexType::INDEX_TYPE_U16, 6);

	mVertex = manager->CreateVertex();

	mUniform = manager->CreateUniform();
}

} /* namespace Example */
