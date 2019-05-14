/*
 * GHIRenderElement.h
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_BATCH_GHIRENDERELEMENT_H_
#define SOURCE_CORE_GHI_BATCH_GHIRENDERELEMENT_H_

#include <cstdint>

namespace GHI
{
class Draw;
class RenderItem;
class RenderElement
{
public:
	RenderElement(RenderItem* parent, Draw* draw);
	~RenderElement(void);

public:
	inline RenderElement& operator=(const RenderElement& other)
	{
		mDraw = other.mDraw;
		mParent = other.mParent;
		return *this;
	}

	inline bool operator==(const RenderElement& other) const
	{
			return (mDraw == other.mDraw);
	}

public:
	inline Draw* GetDraw(void) { return mDraw; }
	inline RenderItem* GetParent(void) const { return mParent; }

protected:
	Draw* mDraw = nullptr;
	RenderItem* mParent = nullptr;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_BATCH_GHIRENDERELEMENT_H_ */
