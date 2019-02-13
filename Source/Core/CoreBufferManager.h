/*
 * CoreBufferManager.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREBUFFERMANAGER_H_
#define SOURCE_CORE_COREBUFFERMANAGER_H_

#include <vector>

namespace Core
{
class Index;
class Vertex;
class Uniform;
class System;
class BufferManager
{
	friend class System;
private:
	explicit BufferManager(System* system);
	virtual ~BufferManager(void);

public:
	Index* CreateIndex(void);
	Vertex* CreateVertex(void);
	Uniform* CreateUniform(void);

public:
	inline System* GetSystem(void) const { return mSystem; }

protected:
	System* mSystem = nullptr;

protected:
	std::vector<Index*> mIndexes;
	std::vector<Vertex*> mVertexes;
	std::vector<Uniform*> mUniforms;

};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBUFFERMANAGER_H_ */