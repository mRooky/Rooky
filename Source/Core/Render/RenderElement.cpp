/*
 * RenderDeclaration.cpp
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#include "RenderElement.h"
#include <cassert>

namespace Render
{

Element::Element(uint32_t binding, uint32_t location, uint32_t offset, ElementType type):
		mOffset(offset), mBinding(binding), mLocation(location), mType(type)
{
}

Element::~Element(void)
{
}

size_t Element::GetTypeSize(ElementType type)
{
	switch(type)
	{
	case ElementType::ELEMENT_TYPE_FLOAT1:
		return 1 * sizeof(float);
	case ElementType::ELEMENT_TYPE_FLOAT2:
		return 2 * sizeof(float);
	case ElementType::ELEMENT_TYPE_FLOAT3:
		return 3 * sizeof(float);
	case ElementType::ELEMENT_TYPE_FLOAT4:
		return 4 * sizeof(float);
	default:
		assert(false);
		return 0;
	}
}

} /* namespace Render */
