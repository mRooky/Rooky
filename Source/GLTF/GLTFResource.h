/*
 * =====================================================================================
 *
 *       Filename:  GLTFResource.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_RESOURCE_H
#define SOURCE_GLTF_RESOURCE_H

#include "GLTFObject.h"

namespace GLTF
{

class Manager;
class Resource : public Object
{
public:
	Resource(Manager* manager) :
		mManager(manager)
	{
	}

	virtual ~Resource(void) override
	{
		mManager = nullptr;
	}

public:
	inline Manager* GetManager(void) const { return mManager; }

protected:
	Manager* mManager = nullptr;

};

}

#endif
