/*
 * RenderBlendState.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: rookyma
 */

#include "RenderBlendState.h"
#include <cassert>

namespace Render
{

BlendState::BlendState(void)
{
}

BlendState::~BlendState(void)
{
}

bool BlendState::operator==(const BlendState& other) const
{
	assert(mColorBlends.size() > 0);
	if (mColorBlends.size() == other.mColorBlends.size())
	{
		const size_t count = mColorBlends.size();
		for (size_t index = 0; index < count; ++index)
		{
			if (mColorBlends.at(index) != other.mColorBlends.at(index))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

} /* namespace Render */
