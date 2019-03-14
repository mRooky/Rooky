/*
 * CoreSystem.h
 *
 *  Created on: Feb 13, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESYSTEM_H_
#define SOURCE_CORE_CORESYSTEM_H_

#include "RenderClasses.h"
#include "RenderFormat.h"
#include "RenderMath.h"

namespace Core
{
class Texture;
class BufferManager;
class TextureManager;
class ResourceManager;
class System
{
public:
	System(void);
	virtual ~System(void);

public:
	void Create(void);

public:
	Texture* CreateTexture2D(const char* name, const Render::Extent3& extent, Render::Format format);

public:
	inline Render::Context* GetContext(void) const { return mContext; }

public:
	inline BufferManager* GetBufferManager(void) const { return mBufferManager; }
	inline TextureManager* GetTextureManager(void) const { return mTextureManager; }
	inline ResourceManager* GetResourceManager(void) const { return mResourceManager; }

protected:
	Render::Context* mContext = nullptr;

protected:
	BufferManager* mBufferManager = nullptr;
	TextureManager* mTextureManager = nullptr;
	ResourceManager* mResourceManager = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESYSTEM_H_ */
