/*
 * DirectLine.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_SHAPE_DIRECTLINE_H_
#define DIRECTUI_SHAPE_DIRECTLINE_H_

#include "../DirectShape.h"

namespace Direct
{

class Line: public Shape
{
public:
	Line(void);
	virtual ~Line(void) override;
};

} /* namespace Direct */

#endif /* DIRECTUI_SHAPE_DIRECTLINE_H_ */
