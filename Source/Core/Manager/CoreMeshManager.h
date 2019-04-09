/*
 * CoreMeshManager.h
 *
 *  Created on: Apr 3, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_MANAGER_COREMESHMANAGER_H_
#define SOURCE_CORE_MANAGER_COREMESHMANAGER_H_

#include "CoreInterface.h"
#include <vector>

namespace Core
{
class Mesh;
class BufferManager;
class MeshManager: public Interface
{
	friend class System;
protected:
	explicit MeshManager(System* system);
	virtual ~MeshManager(void) override;

public:
	Mesh* GetMesh(const char* name);
	Mesh* CreateMesh(const char* name);

public:
	inline BufferManager* GetBufferManager(void) const { return mBufferManager; }

protected:
	BufferManager* mBufferManager = nullptr;

protected:
	std::vector<Mesh*> mMeshes;
};

} /* namespace Core */

#endif /* SOURCE_CORE_MANAGER_COREMESHMANAGER_H_ */
