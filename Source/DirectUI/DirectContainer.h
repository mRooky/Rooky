/*
 * DirectContainer.h
 *
 *  Created on: Oct 11, 2018
 *      Author: rookyma
 */

#ifndef DIRECTUI_DIRECTCONTAINER_H_
#define DIRECTUI_DIRECTCONTAINER_H_

#include "DirectControl.h"
#include <vector>

namespace Direct
{

class Container: public Control
{
protected:
	Container(Widget* parent);
	virtual ~Container(void) override;

public:
	void Append(Widget* widget);
	void Remove(Widget* widget);

protected:
	std::vector<Widget*> mChildren;
};

} /* namespace Direct */

#endif /* DIRECTUI_DIRECTCONTAINER_H_ */
