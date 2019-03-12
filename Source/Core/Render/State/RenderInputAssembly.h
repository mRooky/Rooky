/*
 * RenderInputAssembly.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_STATE_RENDERINPUTASSEMBLY_H_
#define SOURCE_CORE_RENDER_STATE_RENDERINPUTASSEMBLY_H_

#include "RenderState.h"

namespace Render
{

class InputAssembly
{
public:
	InputAssembly(void) = default;
	~InputAssembly(void) = default;

public:
	PrimitiveTopology topology = PrimitiveTopology::PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_STATE_RENDERINPUTASSEMBLY_H_ */
