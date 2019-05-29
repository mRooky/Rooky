/*
 * DirectEllipse.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_SHAPE_DIRECTELLIPSE_H_
#define DIRECTUI_SHAPE_DIRECTELLIPSE_H_

#include "../DirectShape.h"

namespace Direct
{

class Ellipse: public Shape
{
public:
	Ellipse(void);
	virtual ~Ellipse(void) override;
};

} /* namespace Direct */

#endif /* DIRECTUI_SHAPE_DIRECTELLIPSE_H_ */
