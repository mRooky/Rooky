/*
 * GHIRenderItem.h
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_BATCH_GHIRENDERITEM_H_
#define SOURCE_CORE_GHI_BATCH_GHIRENDERITEM_H_

#include "GHIClasses.h"
#include "KernelFixedVector.h"
#include "GHIRenderElement.h"
#include <vector>

namespace GHI
{

class RenderItem
{
	constexpr static size_t MAX_SET_COUNT = 32;
public:
	RenderItem(void);
	~RenderItem(void);

public:
	RenderElement* CreateElement(Draw* draw);

public:
	inline void SetIndexBuffer(Resource* buffer) { mIndexBuffer = buffer; }
	inline void SetVertexBuffer(Resource* buffer) { mVertexBuffer = buffer; }

public:
	inline Resource* GetIndexBuffer(void) const { return mIndexBuffer; }
	inline Resource* GetVertexBuffer(void) const { return mVertexBuffer; }

public:
	inline void PushBindingSet(const BindingSet* set) { mBindingSets.PushElement(set); }
	inline size_t GetBindingSetCount(void) const { return mBindingSets.GetElementCount(); }
	inline const BindingSet* GetBindingSet(size_t index) const { return mBindingSets.GetElementAt(index); }

protected:
	Resource* mIndexBuffer = nullptr;
	Resource* mVertexBuffer = nullptr;

protected:
	std::vector<RenderElement> mRenderElements = {};
	Kernel::FixedVector<const BindingSet*, MAX_SET_COUNT> mBindingSets;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_BATCH_GHIRENDERITEM_H_ */
