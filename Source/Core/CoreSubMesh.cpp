/*
 * CoreSubMesh.cpp
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#include "CoreSubMesh.h"
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

} /* namespace Core */
