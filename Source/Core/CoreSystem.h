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
class BufferManager;
class TextureManager;
class BindingManager;
class PipelineManager;
class System
{
public:
	System(void);
	virtual ~System(void);

public:
	void Create(void);

public:
	inline Render::Device* GetDevice(void) const { return mDevice; }

public:
	inline BufferManager* GetBufferManager(void) const { return mBufferManager; }
	inline TextureManager* GetTextureManager(void) const { return mTextureManager; }
	inline BindingManager* GetBindingManager(void) const { return mBindingManager; }
	inline PipelineManager* GetPipelineManager(void) const { return mPipelineManager; }

protected:
	Render::Device* mDevice = nullptr;

protected:
	BufferManager* mBufferManager = nullptr;
	TextureManager* mTextureManager = nullptr;
	BindingManager* mBindingManager = nullptr;
	PipelineManager* mPipelineManager = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESYSTEM_H_ */
