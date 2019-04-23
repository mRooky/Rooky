/*
 * CoreDepthStencil.cpp
 *
 *  Created on: Apr 23, 2019
 *      Author: rookyma
 */

#include "CoreDepthStencil.h"

namespace Core
{

DepthStencil::DepthStencil(TextureManager* manager):
		RenderTarget(manager)
{
}

DepthStencil::~DepthStencil(void)
{
}

} /* namespace Core */
