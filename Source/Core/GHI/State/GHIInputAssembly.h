/*
 * RenderInputAssembly.h
 *
 *  Created on: Mar 12, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDERSTATE_RENDERINPUTASSEMBLY_H_
#define SOURCE_CORE_GHI_RENDERSTATE_RENDERINPUTASSEMBLY_H_

#include "GHIStateEnum.h"

namespace GHI
{

class InputAssembly
{
public:
	InputAssembly(void) = default;
	~InputAssembly(void) = default;

public:
	inline bool operator==(const InputAssembly& other) const
	{
		return topology == other.topology;
	}

public:
	PrimitiveTopology topology = PrimitiveTopology::TRIANGLE_LIST;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDERSTATE_RENDERINPUTASSEMBLY_H_ */
