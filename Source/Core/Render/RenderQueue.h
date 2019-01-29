/*
 * RenderQueue.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERQUEUE_H_
#define SOURCE_CORE_RENDER_RENDERQUEUE_H_

#include "RenderObject.h"

namespace Render
{

class Queue : public Object
{
public:
	explicit Queue(Context* context);
	virtual ~Queue(void) override;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERQUEUE_H_ */
