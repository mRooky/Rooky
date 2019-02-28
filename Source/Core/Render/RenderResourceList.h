/*
 * RenderResourceSet.h
 *
 *  Created on: Feb 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCELIST_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCELIST_H_

#include "RenderBinding.h"
#include <map>

namespace Render
{
class Resource;
class ResourceList
{
public:
	ResourceList(void);
	virtual ~ResourceList(void);

public:
	void SetBinding(uint32_t bind, const Binding& binding);

public:
	inline bool IsDirty(void) const { return mDirty; }

protected:
	bool mDirty = true;

protected:
	std::map<uint32_t, Binding> mResourceBindings;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCELIST_H_ */
