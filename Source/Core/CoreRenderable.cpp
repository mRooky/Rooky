/*
 * CoreRenderable.cpp
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#include "CoreRenderable.h"

namespace Core
{

Renderable::Renderable(void)
{
}

Renderable::~Renderable(void)
{
}

void Renderable::SetIndex(Index* index, size_t offset)
{
	mIndex = index;
	mIndexOffset = offset;
}

void Renderable::SetVertex(Vertex* vertex, size_t offset)
{
	mVertex = vertex;
	mVertexOffset = offset;
}

} /* namespace Core */
