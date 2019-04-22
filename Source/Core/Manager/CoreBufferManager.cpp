/*
 * CoreBufferManager.cpp
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#include "GHIDevice.h"
#include "GHIElement.h"
#include "GHIFactory.h"
#include "GHILayout.h"
#include "CoreBufferManager.h"
#include "CoreIndex.h"
#include "CoreVertex.h"
#include "CoreUniform.h"
#include "CoreSystem.h"

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

GHI::VertexLayout* BufferManager::CreateVertexLayout(const std::vector<GHI::Element>& elements)
{
	GHI::VertexLayout* layout = GetVertexLayout(elements);
	if (layout == nullptr)
	{
		layout = new GHI::VertexLayout;
		layout->SetElement(elements);
		mVertexLayouts.push_back(layout);
	}
	return layout;
}

GHI::VertexLayout* BufferManager::GetVertexLayout(const std::vector<GHI::Element>& elements)
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
