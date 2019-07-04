/*
 * =====================================================================================
 *
 *       Filename:  GLTFManager.h
 *
 * =====================================================================================
 */

#ifndef SOURCE_GLTF_MANAGER_H
#define SOURCE_GLTF_MANAGER_H

#include "../Core/GHI/GHIClasses.h"
#include <cstdint>
#include <vector>

namespace GLTF
{

class Texture;
class Manager
{
public:
	Manager(void);
	~Manager(void);

public:
	inline GHI::Device* GetDevice(void) const { return mDevice; }

protected:
	GHI::Device* mDevice = nullptr;
	std::vector<Texture*> mTextures;
};

}

#endif
