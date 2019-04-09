/*
 * Rect.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_SHAPE_DIRECTRECTANGLE_H_
#define DIRECTUI_SHAPE_DIRECTRECTANGLE_H_

#include "DirectShape.h"

namespace Direct
{

class Rectangle: public Shape
{
public:
	Rectangle(void);
	virtual ~Rectangle(void) override;
};

} /* namespace Direct */

#endif /* DIRECTUI_SHAPE_DIRECTRECTANGLE_H_ */
