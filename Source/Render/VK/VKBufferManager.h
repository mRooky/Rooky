/*
 * VKBufferManager.h
 *
 *  Created on: Feb 1, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_VK_VKBUFFERMANAGER_H_
#define SOURCE_RENDER_VK_VKBUFFERMANAGER_H_

#include "RenderBufferManager.h"

namespace VK
{
class Context;
class BufferManager: public Render::BufferManager
{
public:
	explicit BufferManager(Context* context);
	virtual ~BufferManager(void) override;

public:
	virtual Render::Index* CreateIndexBuffer(void) override;
	virtual Render::Vertex* CreateVertexBuffer(void) override;
	virtual Render::Uniform* CreateUniformBuffer(void) override;
};

} /* namespace VK */

#endif /* SOURCE_RENDER_VK_VKBUFFERMANAGER_H_ */
