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
class BufferManager
{
public:
	BufferManager(void);
	virtual ~BufferManager(void);

public:

protected:
	std::vector<Index*> mIndexes;
	std::vector<Vertex*> mVertexes;
	std::vector<Uniform*> mUniforms;

};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBUFFERMANAGER_H_ */
