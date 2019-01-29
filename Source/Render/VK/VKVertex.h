/*
 * Vertex.h
 *
 *  Created on: Jan 25, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKVERTEX_H_
#define SOURCE_RENDER_VK_VKVERTEX_H_

#include "VKBuffer.h"

namespace VK
{

class Vertex: public Buffer
{
public:
	explicit Vertex(Context* context);
	virtual ~Vertex(void) override;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKVERTEX_H_ */
