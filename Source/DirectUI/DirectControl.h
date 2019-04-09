/*
 * DirectControl.h
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTCONTROL_H_
#define DIRECTUI_DIRECTCONTROL_H_

#include "DirectVertex.h"
#include "DirectWidget.h"
#include "VulkanClasses.h"
#include <array>

namespace Direct
{
class Texture;
class Control : public Widget
{
protected:
	Control(Widget* parent);
	virtual ~Control(void) override;

public:
	inline void SetColor(const Vector4F& color) { mColor = color; }

public:
	inline const Vector4F GetColor(void) const { return mColor; }

public:
	inline void SetBackGround(Texture* texture) { mBackGround = texture; }

public:
	inline Texture* GetBackGround(void) const { return mBackGround; }

public:
	std::array<Vertex, 4> GetVertexes(void) const;

protected:
	Vector4F mColor = {};

protected:
	Texture* mBackGround = nullptr;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTCONTROL_H_ */
