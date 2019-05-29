/*
 * DirectCanvas.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#include "DirectCanvas.h"
#include "Shape/DirectArc.h"
#include "Shape/DirectEllipse.h"
#include "Shape/DirectLine.h"
#include "Shape/DirectPoint.h"
#include "Shape/DirectRectangle.h"
#include <cassert>

namespace Direct
{

Canvas::Canvas(Widget* parent):
		Widget(parent)
{
}

Canvas::~Canvas(void)
{
	Clear();
}

Shape* Canvas::CreateArc(void)
{
	Arc* arc = new Arc;
	assert(false);
	return arc;
}

Shape* Canvas::CreateEllipse(void)
{
	Ellipse* ellipse = new Ellipse;
	assert(false);
	return ellipse;
}

Shape* Canvas::CreateLine(void)
{
	Line* line = new Line;
	assert(false);
	return line;
}

Shape* Canvas::CreatePoint(void)
{
	Point* point = new Point;
	assert(false);
	return point;
}

Shape* Canvas::CreateRectangle(void)
{
	Rectangle* rectangle = new Rectangle;
	assert(false);
	return rectangle;
}

void Canvas::Clear(void)
{
	for(auto shape : m_shapes)
	{
		delete shape;
	}
	m_shapes.clear();
}

} /* namespace Direct */
