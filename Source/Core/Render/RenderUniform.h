/*
 * RenderUniformBuffer.h
 *
 *  Created on: Feb 1, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERUNIFORM_H_
#define SOURCE_CORE_RENDER_RENDERUNIFORM_H_

#include "RenderBuffer.h"

namespace Render
{

class Uniform : Buffer
{
protected:
	explicit Uniform(BufferManager* manager);
	virtual ~Uniform(void) override;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERUNIFORM_H_ */
