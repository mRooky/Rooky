/*
 * RenderDrawIndexedIndirect.cpp
 *
 *  Created on: Feb 26, 2019
 *      Author: rookyma
 */

#include "GHIDrawIndexedIndirect.h"

namespace GHI
{

DrawIndexedIndirect::DrawIndexedIndirect(void)
{
	mType = DrawType::DRAW_TYPE_INDIRECT;
}

DrawIndexedIndirect::~DrawIndexedIndirect(void)
{
}

} /* namespace Render */
