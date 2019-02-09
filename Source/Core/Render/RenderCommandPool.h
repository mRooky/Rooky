/*
 * RenderCommandPool.h
 *
 *  Created on: Jan 28, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERCOMMANDPOOL_H_
#define SOURCE_CORE_RENDER_RENDERCOMMANDPOOL_H_

#include "RenderObject.h"
#include <cstdint>
#include <vector>

namespace Render
{
class CommandList;
class CommandPool : public Object
{
public:
	explicit CommandPool(Context* context);
	virtual ~CommandPool(void) override;

public:
	virtual void Create(void) = 0;
	virtual CommandList* Allocate(bool primary) = 0;

protected:
	std::vector<CommandList*> mCommandLists;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERCOMMANDPOOL_H_ */
