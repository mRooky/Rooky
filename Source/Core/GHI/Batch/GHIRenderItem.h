/*
 * GHIRenderItem.h
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_BATCH_GHIRENDERITEM_H_
#define SOURCE_CORE_GHI_BATCH_GHIRENDERITEM_H_

#include "GHIClasses.h"
#include "KernelEmbedArray.h"

namespace GHI
{

class RenderItem
{
	constexpr static size_t MAX_SET_COUNT = 32;
public:
	RenderItem(void);
	~RenderItem(void);

public:
	inline void SetPipeline(Pipeline* pipeline) { mPipeline = pipeline; }
	inline void SetIndexBuffer(Resource* buffer) { mIndexBuffer = buffer; }
	inline void SetVertexBuffer(Resource* buffer) { mVertexBuffer = buffer; }

public:
	inline Pipeline* GetPipeline(void) const { return mPipeline; }
	inline Resource* GetIndexBuffer(void) const { return mIndexBuffer; }
	inline Resource* GetVertexBuffer(void) const { return mVertexBuffer; }

public:
	inline void PushBindingSet(const BindingSet* set) { mBindingSets.PushElement(set); }
	inline size_t GetBindingSetCount(void) const { return mBindingSets.GetElementCount(); }
	inline const BindingSet* GetBindingSet(size_t index) const { return mBindingSets.GetElementAt(index); }

protected:
	Pipeline* mPipeline = nullptr;
	Resource* mIndexBuffer = nullptr;
	Resource* mVertexBuffer = nullptr;

protected:
	Kernel::EmbedArray<const BindingSet*, MAX_SET_COUNT> mBindingSets;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_BATCH_GHIRENDERITEM_H_ */
