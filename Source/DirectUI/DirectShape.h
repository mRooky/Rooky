/*
 * DirectShape.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTSHAPE_H_
#define DIRECTUI_DIRECTSHAPE_H_

#include "DirectMath.h"
#include "VulkanClasses.h"

namespace Direct
{
class Painter;
class Shape
{
	friend class Canvas;
protected:
	explicit Shape(Shape* parent = nullptr);
	virtual ~Shape(void);

public:
	virtual Vector2I GetOffset(void) const;

public:
	inline void SetRect(const RectI& rect) { mRect = rect; }
	inline void SetPainter(Painter* painter) { mPainter = painter; }

public:
	inline Painter* GetPainter(void) const { return mPainter; }

protected:
	RectI mRect;
	Shape* mParent = nullptr;
	Painter* mPainter = nullptr;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTSHAPE_H_ */
