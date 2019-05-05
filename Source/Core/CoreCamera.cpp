/*
 * CoreCamera.cpp
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#include "CoreCamera.h"
#include "UtilitySearch.h"
#include <cassert>

namespace Core
{

Camera::Camera(void)
{
}

Camera::~Camera(void)
{
}

void Camera::UpdateUniform(void)
{
	if (mUniform != nullptr)
	{

	}
}

void Camera::AppendRenderable(Renderable* renderable)
{
	auto iterator = Utility::Find(mRenderables, renderable);
	if (iterator == mRenderables.end())
	{
		mRenderables.push_back(renderable);
	}
}

} /* namespace Core */
