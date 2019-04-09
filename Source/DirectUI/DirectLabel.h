/*
 * Label.h
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_LABEL_H_
#define DIRECTUI_LABEL_H_

#include "DirectControl.h"
#include <string>

namespace Direct
{
class Label: public Control
{
public:
	Label(Widget* parent = nullptr);
	virtual ~Label(void) override;

public:
	virtual void Draw(Surface* surface) override;

public:
	inline const char* GetCaption(void) const { return mCaption.c_str(); }

public:
	inline void SetForeGround(Texture* texture) { mForeGround = texture; }
	inline void SetForeMask(Texture* texture) { mForeMask = texture; }

public:
	inline Texture* GetForeGround(void) const { return mForeGround; }
	inline Texture* GetForeMask(void) const { return mForeMask; }

protected:
	Texture* mForeGround = nullptr;
	Texture* mForeMask = nullptr;

protected:
	std::string mCaption = "";
};

} /* namespace Direct */

#endif /* DIRECTUI_LABEL_H_ */
