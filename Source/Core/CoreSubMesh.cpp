/*
 * CoreSubMesh.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "CoreSubMesh.h"
#include "CoreMesh.h"
#include <cassert>

namespace Core
{

SubMesh::SubMesh(Mesh* parent):
		mParent(parent)
{
	assert(mParent != nullptr);
}

SubMesh::~SubMesh(void)
{
}

bool SubMesh::IsVisible(const Math::Frustum& frustum)
{
	const auto* aabb = mParent->GetAABB();
	return frustum.Contain(*aabb);
}

} /* namespace Core */
