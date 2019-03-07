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
#include "RenderDeclaration.h"
#include "RenderContext.h"
#include "RenderFactory.h"

#include "UtilRelease.h"

#include <cassert>

namespace Core
{

BufferManager::BufferManager(System* system):
		mSystem(system)
{
	assert(mSystem != nullptr);
}

BufferManager::~BufferManager(void)
{
	mSystem = nullptr;
	Util::Release(mIndexes);
	Util::Release(mVertexes);
	Util::Release(mUniforms);
	Util::Release(mDeclarations);
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

Render::Declaration* BufferManager::CreateDeclaration(const std::vector<Render::Element>& elements)
{
	for (auto decl : mDeclarations)
	{
		auto& list = decl->GetElements();
		if (elements == list)
		{
			return decl;
		}
	}
	auto context = mSystem->GetContext();
	auto factory = context->GetFactory();
	Render::Declaration* decl = factory->CreateDeclaration();
	decl->Create(elements);
	mDeclarations.push_back(decl);
	return decl;
}

} /* namespace Core */
