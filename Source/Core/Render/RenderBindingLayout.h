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
#include <vector>

namespace Render
{
class BindingSet;
class PipelineLayout;
class BindingLayout : public Object
{
public:
	explicit BindingLayout(Device* device);
	virtual ~BindingLayout(void) override;

public:
	virtual void Create(void) = 0;

public:
	virtual void AppendBindingSet(const BindingSet* set) = 0;
	virtual void SetBindingSet(size_t index, const BindingSet* set) = 0;

public:
	virtual BindingSet* CreateSet(void) = 0;

public:
	inline size_t GetStateCount(void) const { return mBindingSets.size(); }
	inline PipelineLayout* GetPipelineLayout(void) const { return mPipelineLayout; }
	inline BindingSet* GetBindingSet(size_t index) const { return mBindingSets.at(index); }

protected:
	bool mDirty = true;
	PipelineLayout* mPipelineLayout = nullptr;

protected:
	std::vector<BindingSet*> mBindingSets;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBINDINGLAYOUT_H_ */
