/*
 * RenderVertex.h
 *
 *  Created on: Jan 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERVERTEX_H_
#define SOURCE_CORE_RENDER_RENDERVERTEX_H_

#include "RenderBuffer.h"
#include "RenderFormat.h"
#include <vector>

namespace Render
{

class Vertex: public Buffer
{
public:
	explicit Vertex(Context* context);
	virtual ~Vertex(void) override;

protected:
	std::vector<Format> mFormats;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERVERTEX_H_ */
