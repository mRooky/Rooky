/*
 * RenderCommandPool.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERCOMMANDPOOL_H_
#define SOURCE_CORE_GHI_RENDERCOMMANDPOOL_H_

#include "GHIObject.h"
#include <cstdint>
#include <vector>

namespace GHI
{
class CommandList;
class CommandPool : public Object
{
public:
	explicit CommandPool(Device* device);
	virtual ~CommandPool(void) override;

public:
	virtual void Create(void) = 0;
	virtual CommandList* Allocate(bool primary) = 0;

public:
	inline size_t GetCommandListCount(void) const { return mCommandLists.size(); }
	inline CommandList* GetCommandList(size_t index) const { return mCommandLists.at(index); }

protected:
	std::vector<CommandList*> mCommandLists;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERCOMMANDPOOL_H_ */
