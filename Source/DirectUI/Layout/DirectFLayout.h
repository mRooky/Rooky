/*
 * DirectFLayout.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_LAYOUT_DIRECTFLAYOUT_H_
#define DIRECTUI_LAYOUT_DIRECTFLAYOUT_H_

#include "../DirectLayout.h"

namespace Direct
{

class FLayout: public Layout
{
public:
	FLayout(Widget* parent = nullptr);
	virtual ~FLayout(void);
};

} /* namespace Direct */

#endif /* DIRECTUI_LAYOUT_DIRECTFLAYOUT_H_ */
