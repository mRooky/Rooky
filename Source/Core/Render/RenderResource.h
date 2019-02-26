/*
 * RenderResource.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCE_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCE_H_

#include "RenderObject.h"
#include "RenderTypes.h"
#include <cstddef>
#include <cstdint>

namespace Render
{
class Resource : public Object
{
protected:
	explicit Resource(Context* context);
	virtual ~Resource(void) override;

};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCE_H_ */
