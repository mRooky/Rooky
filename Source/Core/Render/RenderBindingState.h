/*
 * RenderResourceList.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBINDINGSTATE_H_
#define SOURCE_CORE_RENDER_RENDERBINDINGSTATE_H_

#include "RenderBinding.h"
#include <vector>

namespace Render
{

class BindingLayout;
class BindingState
{
public:
	BindingState(BindingLayout* layout);
	virtual ~BindingState(void);

public:
	virtual void Update(void) = 0;

public:
	void AppendResource(const Binding& binding);

protected:
	BindingLayout* mLayout = nullptr;
	std::vector<Binding> mBindings;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBINDINGSTATE_H_ */
