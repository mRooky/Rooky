/*
 * RenderResource.h
 *
 *  Created on: Mar 20, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERRESOURCE_H_
#define SOURCE_CORE_RENDER_RENDERRESOURCE_H_

#include "RenderObject.h"

namespace Render
{

class Resource: public Object
{
public:
	explicit Resource(Context* context);
	virtual ~Resource(void) override;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERRESOURCE_H_ */
