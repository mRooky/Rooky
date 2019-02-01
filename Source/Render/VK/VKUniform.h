/*
 * VKUniform.h
 *
 *  Created on: Feb 1, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKUNIFORM_H_
#define SOURCE_RENDER_VK_VKUNIFORM_H_

#include "RenderUniform.h"

namespace VK
{
class BufferManager;
class Uniform: public Render::Uniform
{
public:
	explicit Uniform(BufferManager* manager);
	virtual ~Uniform(void) override;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKUNIFORM_H_ */
