/*
 * Sampler.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERSAMPLER_H_
#define SOURCE_CORE_RENDER_RENDERSAMPLER_H_

#include "RenderObject.h"

namespace Render
{

class Sampler: public Object
{
public:
	explicit Sampler(Context* context);
	virtual ~Sampler(void) override;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERSAMPLER_H_ */
