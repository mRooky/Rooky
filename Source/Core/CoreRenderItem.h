/*
 * CoreRenderItem.h
 *
 *  Created on: May 9, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORERENDERITEM_H_
#define SOURCE_CORE_CORERENDERITEM_H_

#include "GHIClasses.h"
#include "KernelArray.h"
#include <array>

namespace Core
{
class RenderItem
{
	constexpr static size_t MAX_SET_COUNT = 32;
public:
	RenderItem(void);
	~RenderItem(void);

public:
	inline void SetPipeline(GHI::Pipeline* pipeline) { mPipeline = pipeline; }
	inline void SetIndexBuffer(GHI::Resource* buffer) { mIndexBuffer = buffer; }
	inline void SetVertexBuffer(GHI::Resource* buffer) { mVertexBuffer = buffer; }

public:
	inline GHI::Pipeline* GetPipeline(void) const { return mPipeline; }
	inline GHI::Resource* GetIndexBuffer(void) const { return mIndexBuffer; }
	inline GHI::Resource* GetVertexBuffer(void) const { return mVertexBuffer; }

public:
	inline void PushBindingSet(const GHI::BindingSet* set) { mBindingSets.Append(set); }
	inline size_t GetBindingSetCount(void) const { return mBindingSets.GetElementCount(); }
	inline const GHI::BindingSet* GetBindingSet(size_t index) const { return mBindingSets.GetElementAt(index); }

protected:
	GHI::Pipeline* mPipeline = nullptr;
	GHI::Resource* mIndexBuffer = nullptr;
	GHI::Resource* mVertexBuffer = nullptr;

protected:
	Kernel::Array<const GHI::BindingSet*, MAX_SET_COUNT> mBindingSets;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORERENDERITEM_H_ */
