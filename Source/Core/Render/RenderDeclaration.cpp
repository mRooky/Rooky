/*
 * RenderDeclaration.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: rookyma
 */

#include "RenderDeclaration.h"

#include <cassert>

namespace Render
{

Declaration::Declaration(void)
{
}

Declaration::~Declaration(void)
{
}

void Declaration::Create(const std::vector<Element>& elements)
{
	for (auto& element : elements)
	{
		mElements.push_back(element);
		mStride += GetFormatSize(element.GetFormat());
	}
}

} /* namespace Render */
