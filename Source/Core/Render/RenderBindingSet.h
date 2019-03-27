/*
 * RenderResourceList.h
 *
 *  Created on: Mar 5, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBINDINGSET_H_
#define SOURCE_CORE_RENDER_RENDERBINDINGSET_H_

#include "RenderObject.h"
#include "RenderBinding.hpp"
#include <vector>

static const size_t MAX_BINDING_PER_SET = 8;
namespace Render
{
class BindingSet : public Object
{
protected:
	explicit BindingSet(Device* device);

public:
	virtual ~BindingSet(void) override;

public:
	virtual void Update(void) = 0;

public:
	void SetBinding(uint32_t index, const Binding& binding);

public:
	inline bool IsValid(void) const { return mValid; }
	inline void AppendBinding(const Binding& binding) { mBindings.push_back(binding); }
	inline const Binding& GetBinding(size_t index) const { return mBindings.at(index); }

protected:
	bool mValid = false;
	std::vector<Binding> mBindings;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBINDINGSET_H_ */
