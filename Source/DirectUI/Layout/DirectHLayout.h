/*
 * DirectHLayout.h
 *
 *  Created on: Nov 24, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTHLAYOUT_H_
#define DIRECTUI_DIRECTHLAYOUT_H_

#include "DirectLayout.h"

namespace Direct
{

class HLayout: public Layout
{
public:
	HLayout(Widget* parent = nullptr);
	virtual ~HLayout(void) override;

public:
	void Draw(Surface* surface) override;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTHLAYOUT_H_ */
