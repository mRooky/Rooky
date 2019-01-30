/*
 * Vertex.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKVERTEX_H_
#define SOURCE_RENDER_VK_VKVERTEX_H_

#include "RenderVertex.h"

namespace VK
{
class Context;
class Vertex: public Render::Vertex
{
public:
	explicit Vertex(Context* context);
	virtual ~Vertex(void) override;

public:
	virtual void Initialize(Render::Declaration* decl, size_t count) override;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKVERTEX_H_ */
