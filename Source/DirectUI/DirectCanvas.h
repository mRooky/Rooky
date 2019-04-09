/*
 * DirectCanvas.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTCANVAS_H_
#define DIRECTUI_DIRECTCANVAS_H_

#include "DirectWidget.h"
#include <vector>

namespace Direct
{
class Shape;
class Canvas : public Widget
{
public:
	Canvas(Widget* parent = nullptr);
	virtual ~Canvas(void) override;

public:
	void Clear(void);

public:
	Shape* CreateArc(void);
	Shape* CreateEllipse(void);
	Shape* CreateLine(void);
	Shape* CreatePoint(void);
	Shape* CreateRectangle(void);

private:
	std::vector<Shape*> m_shapes;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTCANVAS_H_ */
