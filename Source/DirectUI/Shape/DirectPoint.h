/*
 * DirectPoint.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_SHAPE_DIRECTPOINT_H_
#define DIRECTUI_SHAPE_DIRECTPOINT_H_

#include "DirectShape.h"

namespace Direct
{

class Point: public Shape
{
public:
	Point(void);
	virtual ~Point(void) override;
};

} /* namespace Direct */

#endif /* DIRECTUI_SHAPE_DIRECTPOINT_H_ */
