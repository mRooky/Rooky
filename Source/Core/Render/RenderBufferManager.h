/*
 * RenderBufferManager.h
 *
 *  Created on: Feb 1, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERBUFFERMANAGER_H_
#define SOURCE_CORE_RENDER_RENDERBUFFERMANAGER_H_

#include "RenderObject.h"
#include "RenderClasses.h"
#include <vector>

namespace Render
{
class BufferManager: public Object
{
protected:
	explicit BufferManager(Context* context);
	virtual ~BufferManager(void) override;

public:
	virtual Index* CreateIndexBuffer(void) = 0;
	virtual Vertex* CreateVertexBuffer(void) = 0;
	virtual Uniform* CreateUniformBuffer(void) = 0;

public:
	inline size_t GetIndexCount(void) const { return mIndexes.size(); }
	inline size_t GetVertexCount(void) const { return mVertexes.size(); }
	inline size_t GetUniformCount(void) const { return mUniforms.size(); }

public:
	inline Index* GetIndexBuffer(size_t index) const { return mIndexes.at(index); }
	inline Vertex* GetVertexBuffer(size_t index) const { return mVertexes.at(index); }
	inline Uniform* GetUniformBuffer(size_t index) const { return mUniforms.at(index); }

protected:
	std::vector<Index*> mIndexes;
	std::vector<Vertex*> mVertexes;
	std::vector<Uniform*> mUniforms;
};

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERBUFFERMANAGER_H_ */
