/*
 * RenderQueue.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERQUEUE_H_
#define SOURCE_CORE_RENDER_RENDERQUEUE_H_

#include "RenderObject.h"
#include <cstdint>

namespace Render
{
class CommandList;
class Queue : public Object
{
public:
	explicit Queue(Context* context);
	virtual ~Queue(void) override;

public:
	virtual void Create(uint32_t mIndex) = 0;

public:
	virtual void Submit(CommandList* command) = 0;

protected:
	uint32_t mIndex = 0;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERQUEUE_H_ */
