/*
 * RenderResourceLayout.h
 *
 *  Created on: Mar 6, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERBINDINGLAYOUT_H_
#define SOURCE_CORE_GHI_RENDERBINDINGLAYOUT_H_

#include <cstddef>
#include <vector>

namespace GHI
{
class BindingSet;
class PipelineLayout;
class BindingLayout
{
public:
	BindingLayout(void);
	virtual ~BindingLayout(void);

public:
	void AppendBindingSet(const BindingSet* set);
	void PushBindingSet(size_t index, const BindingSet* set);

public:
	inline size_t GetSetCount(void) const { return mBindingSets.size(); }
	inline const BindingSet* GetBindingSet(size_t index) const { return mBindingSets.at(index); }

protected:
	bool mDirty = true;

protected:
	std::vector<const BindingSet*> mBindingSets;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERBINDINGLAYOUT_H_ */
