/*
 * RenderContext.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_RENDER_RENDERDEVICE_H_
#define SOURCE_CORE_RENDER_RENDERDEVICE_H_

#include "RenderFormat.h"
#include <vector>

namespace Render
{
class Factory;
class Device
{
protected:
	Device(void);

public:
	virtual ~Device(void);

public:
	virtual void Create(void) = 0;

public:
	inline Factory* GetFactory(void) const { return mFactory; }

protected:
	Factory* mFactory = nullptr;

public:
	virtual Format GetBestDepthStencilFormat(void) = 0;
};

Device* CreateDevice(void);
void DestroyDevice(Device* device);

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERDEVICE_H_ */
