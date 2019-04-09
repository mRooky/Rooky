/*
 * DirectButton.h
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTBUTTON_H_
#define DIRECTUI_DIRECTBUTTON_H_

#include "DirectEvent.h"
#include "DirectLabel.h"

namespace Direct
{
class Button: public Label
{

public:
	Button(Widget* parent = nullptr);
	virtual ~Button(void) override;

public:
	virtual void Draw(Surface* surface) override;

protected:
	Event mEvent;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTBUTTON_H_ */
