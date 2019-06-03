/*
 * GHIRenderItem.h
 *
 *  Created on: May 14, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_BATCH_GHIRENDERITEM_H_
#define SOURCE_CORE_GHI_BATCH_GHIRENDERITEM_H_

#include "GHIRenderBuffer.h"
#include "GHIRenderElement.h"

#include "../../Kernel/KernelVector.h"

#include <vector>

namespace GHI
{
class BindingSet;
class RenderItem
{
	constexpr static const size_t MAX_SET_COUNT = 32;
public:
	RenderItem(void);
	~RenderItem(void);

public:
	void Render(CommandList* command);

public:
	void AppendElement(Draw* draw);
	void AppendElement(const RenderElement& element) { mRenderElements.push_back(element); }

public:
	inline IndexBuffer* GetIndexBuffer(void) { return &mIndexBuffer; }
	inline VertexAttribute* GetVertexAttribute(void) { return &mVertexAttribute; }

public:
	inline void PushBindingSet(BindingSet* set) { mBindingSets.PushElement(set); }
	inline size_t GetBindingSetCount(void) const { return mBindingSets.GetElementCount(); }
	inline const BindingSet* GetBindingSet(size_t index) const { return mBindingSets.GetElementAt(index); }

protected:
	void BindingBindingSet(CommandList* command);
	void BindingIndexBuffer(CommandList* command);
	void BindingVertexBuffer(CommandList* command);

protected:
	IndexBuffer mIndexBuffer = {};
	VertexAttribute mVertexAttribute = {};

protected:
	std::vector<RenderElement> mRenderElements = {};
	Kernel::FixedVector<BindingSet*, MAX_SET_COUNT> mBindingSets;
};

} /* namespace GHI */

#endif /* SOURCE_CORE_GHI_BATCH_GHIRENDERITEM_H_ */
