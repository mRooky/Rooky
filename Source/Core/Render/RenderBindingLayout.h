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
class BindingSet;
class PipelineLayout;
class BindingLayout : public Object
{
public:
	explicit BindingLayout(Context* context);
	virtual ~BindingLayout(void) override;

public:
	virtual BindingSet* CreateState(void) = 0;
	virtual PipelineLayout* CreatePipelineLayout(void) = 0;

public:
	inline void ClearState(void) { mResourceMask.reset(); }
	inline PipelineLayout* GetPipelineLayout(void) const { return mPipelineLayout; }

public:
	inline size_t GetStateCount(void) const { return mBindingSets.size(); }
	inline BindingSet* GetBindingSet(size_t index) const { return mBindingSets.at(index); }

protected:
	bool mDirty = true;
	PipelineLayout* mPipelineLayout = nullptr;
	std::bitset<8> mResourceMask = 0;
	std::array<BindingSet*, 8> mBindingSets;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBINDINGLAYOUT_H_ */
