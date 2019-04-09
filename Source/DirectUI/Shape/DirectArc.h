/*
 * DirectArc.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_SHAPE_DIRECTARC_H_
#define DIRECTUI_SHAPE_DIRECTARC_H_

#include "DirectShape.h"

namespace Direct
{

class Arc: public Shape
{
public:
	Arc(void);
	virtual ~Arc(void) override;
};

} /* namespace Direct */

#endif /* DIRECTUI_SHAPE_DIRECTARC_H_ */
