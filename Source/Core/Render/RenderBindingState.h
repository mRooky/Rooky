/*
 * RenderResourceList.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBINDINGSTATE_H_
#define SOURCE_CORE_RENDER_RENDERBINDINGSTATE_H_

#include "RenderBinding.hpp"
#include <array>
#include <bitset>

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
	virtual void SetBinding(uint32_t index, const Binding& binding) = 0;

public:
	inline BindingLayout* GetBindingLayout(void) const { return mLayout; }
	inline const Binding& GetBinding(size_t index) const { return mBindings.at(index); }

protected:
	BindingLayout* mLayout = nullptr;
	std::bitset<8> mBindingMask = 0;
	std::array<Binding, 8> mBindings;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBINDINGSTATE_H_ */
