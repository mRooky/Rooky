/*
 * CoreBufferManager.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREBUFFERMANAGER_H_
#define SOURCE_CORE_COREBUFFERMANAGER_H_

#include "GHIClasses.h"
#include "GHIElement.h"
#include "GHIFormat.h"
#include "CoreInterface.h"
#include <vector>

namespace Core
{
class Index;
class Vertex;
class Uniform;
class BufferManager : public Interface
{
	friend class MeshManager;
private:
	explicit BufferManager(System* system);
	virtual ~BufferManager(void) override;

public:
	Index* CreateIndex(void);
	Vertex* CreateVertex(void);
	Uniform* CreateUniform(void);

public:
	GHI::VertexLayout* CreateVertexLayout(const std::vector<GHI::Element>& elements);

public:
	inline System* GetSystem(void) const { return mSystem; }

protected:
	GHI::VertexLayout* GetVertexLayout(const std::vector<GHI::Element>& elements);

protected:
	std::vector<Index*> mIndexes;
	std::vector<Vertex*> mVertexes;
	std::vector<Uniform*> mUniforms;

protected:
	std::vector<GHI::VertexLayout*> mVertexLayouts;

};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBUFFERMANAGER_H_ */
