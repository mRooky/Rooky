/*
 * DirectBLayout.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_LAYOUT_DIRECTBLAYOUT_H_
#define DIRECTUI_LAYOUT_DIRECTBLAYOUT_H_

#include "../DirectLayout.h"

namespace Direct
{

class BLayout: public Layout
{
public:
	BLayout(Widget* parent = nullptr);
	virtual ~BLayout(void) override;
};

} /* namespace Direct */

#endif /* DIRECTUI_LAYOUT_DIRECTBLAYOUT_H_ */
