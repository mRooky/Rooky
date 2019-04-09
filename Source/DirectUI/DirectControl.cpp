/*
 * DirectControl.cpp
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#include "DirectControl.h"
#include <cassert>

namespace Direct
{

Control::Control(Widget* parent):
		Widget(parent)
{
}

Control::~Control(void)
{
	mBackGround = nullptr;
}

std::array<Vertex, 4> Control::GetVertexes(void) const
{
	std::array<Vertex, 4> vertexes;
	{
		assert(false);
		/*
		vertexes[0].SetPosition(rect.min.x, rect.min.y);
		vertexes[0].SetTexCoord(mCoord.min.x, mCoord.min.y);
		vertexes[0].SetColor(mColor.x, mColor.y, mColor.z, mColor.w);

		vertexes[1].SetPosition(rect.max.x, rect.min.y);
		vertexes[1].SetTexCoord(mCoord.max.x, mCoord.min.y);
		vertexes[1].SetColor(mColor.x, mColor.y, mColor.z, mColor.w);

		vertexes[2].SetPosition(rect.max.x, rect.max.y);
		vertexes[2].SetTexCoord(mCoord.max.x, mCoord.max.y);
		vertexes[2].SetColor(mColor.x, mColor.y, mColor.z, mColor.w);

		vertexes[3].SetPosition(rect.min.x, rect.max.y);
		vertexes[3].SetTexCoord(mCoord.min.x, mCoord.max.y);
		vertexes[3].SetColor(mColor.x, mColor.y, mColor.z, mColor.w);
		*/
	}
	return vertexes;
}

} /* namespace Direct */
