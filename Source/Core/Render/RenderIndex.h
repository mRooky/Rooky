/*
 * RenderIndex.h
 *
 *  Created on: Jan 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERINDEX_H_
#define SOURCE_CORE_RENDER_RENDERINDEX_H_

#include "RenderBuffer.h"

namespace Render
{

class Index: public Buffer
{
public:
	explicit Index(Context* context);
	virtual ~Index(void) override;

protected:

};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERINDEX_H_ */
