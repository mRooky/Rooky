/*
 * CoreBufferManager.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "CoreBufferManager.h"
#include "CoreIndex.h"
#include "CoreVertex.h"
#include "CoreUniform.h"
#include "CoreSystem.h"

#include "RenderElement.h"
#include "RenderVertexLayout.h"
#include "RenderFactory.h"
#include "RenderDevice.h"
#include "UtilityRelease.h"

#include <cassert>

namespace Core
{

BufferManager::BufferManager(System* system):
		Interface(system)
{
}

BufferManager::~BufferManager(void)
{
	Utility::Release(mIndexes);
	Utility::Release(mVertexes);
	Utility::Release(mUniforms);
	Utility::Release(mVertexLayouts);
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
		layout = new Render::VertexLayout;
		layout->SetElement(elements);
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
