/*
 * DirectWidget.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTWIDGET_H_
#define DIRECTUI_DIRECTWIDGET_H_

#include "DirectShape.h"

namespace Direct
{
class Surface;
class Widget : public Shape
{
	friend class Surface;
protected:
	Widget(Widget* parent);
	virtual ~Widget(void) override;

public:
	virtual void Draw(Surface* surface) = 0;

public:
	VkImageCopy GetCopyRegion(void) const;

public:
	inline void SetParent(Widget* parent) { mParent = parent; }
	inline void SetPadding(const RectI& padding) { mPadding = padding; }

public:
	inline Widget* GetParent(void) const { return mParent; }
	inline const RectI& GetPadding(void) const { return mPadding; }

protected:
	RectI mPadding = {};
	Widget* mParent = nullptr;

};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTWIDGET_H_ */
