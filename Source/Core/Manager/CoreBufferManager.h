/*
 * CoreBufferManager.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREBUFFERMANAGER_H_
#define SOURCE_CORE_COREBUFFERMANAGER_H_

#include "CoreObject.h"
#include "RenderClasses.h"
#include "RenderFormat.h"
#include "RenderElement.h"
#include <vector>

namespace Core
{
class Index;
class Vertex;
class Uniform;
class BufferManager : public Object
{
	friend class System;
private:
	explicit BufferManager(System* system);
	virtual ~BufferManager(void) override;

public:
	Index* CreateIndex(void);
	Vertex* CreateVertex(void);
	Uniform* CreateUniform(void);

public:
	Render::VertexLayout* CreateVertexLayout(const std::vector<Render::Element>& elements);

public:
	inline System* GetSystem(void) const { return mSystem; }

protected:
	Render::VertexLayout* GetVertexLayout(const std::vector<Render::Element>& elements);

protected:
	std::vector<Index*> mIndexes;
	std::vector<Vertex*> mVertexes;
	std::vector<Uniform*> mUniforms;

protected:
	std::vector<Render::VertexLayout*> mVertexLayouts;

};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBUFFERMANAGER_H_ */
