/*
 * RenderResourceLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBINDINGLAYOUT_H_
#define SOURCE_CORE_RENDER_RENDERBINDINGLAYOUT_H_

#include "RenderObject.h"
#include <cstddef>
#include <array>
#include <bitset>

namespace Render
{
class BindingState;
class PipelineLayout;
class BindingLayout : public Object
{
public:
	explicit BindingLayout(Context* context);
	virtual ~BindingLayout(void) override;

public:
	void SetResourceState(uint32_t index, BindingState* state);

public:
	virtual PipelineLayout* Update(void) = 0;
	virtual BindingState* CreateState(void) = 0;

public:
	inline void ClearState(void) { mResourceMask.reset(); }
	inline PipelineLayout* GetCurrentLayout(void) const { return mCurrentLayout; }

public:
	inline size_t GetStateCount(void) const { return mBindingStates.size(); }
	inline BindingState* GetBindingState(size_t index) const { return mBindingStates.at(index); }

protected:
	bool mDirty = true;
	PipelineLayout* mCurrentLayout = nullptr;
	std::bitset<8> mResourceMask = 0;
	std::array<BindingState*, 8> mBindingStates;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBINDINGLAYOUT_H_ */
