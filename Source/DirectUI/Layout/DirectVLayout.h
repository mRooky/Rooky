/*
 * DirectVLayout.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTVLAYOUT_H_
#define DIRECTUI_DIRECTVLAYOUT_H_

#include "../DirectLayout.h"

namespace Direct
{

class VLayout: public Layout
{
public:
	VLayout(Widget* parent = nullptr);
	virtual ~VLayout(void) override;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTVLAYOUT_H_ */
