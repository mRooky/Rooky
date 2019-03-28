/*
 * CoreBufferManager.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include <RenderDevice.h>
#include "CoreBufferManager.h"
#include "CoreIndex.h"
#include "CoreVertex.h"
#include "CoreUniform.h"
#include "CoreSystem.h"

#include "RenderElement.h"
#include "RenderVertexLayout.h"
#include "RenderFactory.h"

#include "UtilRelease.h"

#include <cassert>

namespace Core
{

BufferManager::BufferManager(System* system):
		Object(system)
{
}

BufferManager::~BufferManager(void)
{
	Util::Release(mIndexes);
	Util::Release(mVertexes);
	Util::Release(mUniforms);
	Util::Release(mVertexLayouts);
}

Index* BufferManager::CreateIndex(void)
{
	Index* index = new Index(this);
	mIndexes.push_back(index);
	return index;
}

Vertex* BufferManager::CreateVertex(void)
{
	Vertex* vertex = new Vertex(this);
	mVertexes.push_back(vertex);
	return vertex;
}

Uniform* BufferManager::CreateUniform(void)
{
	Uniform* uniform = new Uniform(this);
	mUniforms.push_back(uniform);
	return uniform;
}

Render::VertexLayout* BufferManager::CreateVertexLayout(const std::vector<Render::Element>& elements)
{
	Render::VertexLayout* layout = GetVertexLayout(elements);
	if (layout == nullptr)
	{
		auto device = mSystem->GetDevice();
		auto factory = device->GetFactory();
		layout = factory->CreateVertexLayout();
		layout->SetElement(elements);
		layout->Create();
		mVertexLayouts.push_back(layout);
	}
	return layout;
}

Render::VertexLayout* BufferManager::GetVertexLayout(const std::vector<Render::Element>& elements)
{
	for (auto layout : mVertexLayouts)
	{
		const auto& list = layout->GetElements();
		if (elements == list)
		{
			return layout;
		}
	}
	return nullptr;
}

} /* namespace Core */
