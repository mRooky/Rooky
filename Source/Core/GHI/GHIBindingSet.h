/*
 * RenderResourceList.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERBINDINGSET_H_
#define SOURCE_CORE_GHI_RENDERBINDINGSET_H_

#include "GHIBinding.h"
#include "GHIObject.h"

#include "../Kernel/KernelFixedVector.h"
#include <vector>

namespace GHI
{
class BindingSet : public Object
{
	friend class BindingLayout;
	static const size_t MAX_BINDING_COUNT = 8;
protected:
	explicit BindingSet(Device* device);

public:
	virtual ~BindingSet(void) override;

public:
	virtual void Create(void) = 0;

public:
	void AppendBinding(const Binding& binding);
	void SetBinding(uint32_t index, const Binding& binding);

public:
	inline bool IsValid(void) const { return mValid; }

public:
	inline size_t GetBindingCount(void) const { return mBindings.GetElementCount(); }
	inline const Binding& GetBinding(size_t index) const { return mBindings.GetElementAt(index); }

protected:
	bool mValid = false;
	Kernel::FixedVector<Binding, MAX_BINDING_COUNT> mBindings;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERBINDINGSET_H_ */
