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

Element::Element(uint32_t binding, Format format):
		mBinding(binding), mFormat(format)
{
}

Element::~Element(void)
{
}

void Element::Create(uint32_t binding, Format format)
{
	mFormat = format;
	mBinding = binding;
}

} /* namespace Render */
