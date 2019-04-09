/*
 * DirectLayout.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTLAYOUT_H_
#define DIRECTUI_DIRECTLAYOUT_H_

#include "DirectContainer.h"

namespace Direct
{

class Layout: public Container
{
protected:
	Layout(Widget* parent);
	virtual ~Layout(void) override;

public:
	inline void SetSpace(uint32_t space) { mSpace = space; }
	inline uint32_t GetSpace(void) const { return mSpace; }

protected:
	uint32_t mSpace = 0;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTLAYOUT_H_ */
