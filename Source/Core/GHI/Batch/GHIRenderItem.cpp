/*
 * GHIRenderItem.cpp
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#include "GHIRenderItem.h"
#include "../GHICommandList.h"
#include "../GHIBuffer.h"
#include <cassert>

namespace GHI
{

RenderItem::RenderItem(void)
{
}

RenderItem::~RenderItem(void)
{
}

void RenderItem::Render(CommandList* command)
{
	BindingBindingSet(command);
	BindingIndexBuffer(command);
	BindingVertexBuffer(command);
	for (auto& element : mRenderElements)
	{
		element.Render(command);
	}
}

void RenderItem::BindingBindingSet(CommandList* command)
{
	const size_t count = mBindingSets.GetElementCount();
	for (size_t index = 0; index < count; ++index)
	{
		BindingSet* set = mBindingSets.GetElementAt(index);
		command->SetBindingSet(index, set);
	}
}

void RenderItem::BindingIndexBuffer(CommandList* command)
{
	const Buffer* index = mIndexBuffer.GetBuffer();
	if (index != nullptr)
	{
		size_t offset = mIndexBuffer.GetOffset();
		IndexType type = mIndexBuffer.GetType();
		command->SetIndex(index, offset, type);
	}
}

void RenderItem::BindingVertexBuffer(CommandList* command)
{
	const size_t count = mVertexAttribute.GetBufferCount();
	assert(count > 0);
	for (size_t index = 0; index < count; ++index)
	{
		const auto& vertex = mVertexAttribute.GetBuffer(index);
		size_t offset = vertex.GetOffset();
		const Resource* resource = vertex.GetBuffer();
		command->SetVertex(resource, index, offset);
	}
}

void RenderItem::AppendElement(Draw* draw)
{
	RenderElement element(this, draw);
	mRenderElements.push_back(element);
}

} /* namespace GHI */
