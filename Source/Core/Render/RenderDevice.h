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
class Queue;
class Vendor;
class Factory;
class Device
{
protected:
	Device(void);

public:
	virtual ~Device(void);

public:
	virtual void Create(void) = 0;
	virtual Format GetBestDepthStencilFormat(void) = 0;

public:
	inline Factory* GetFactory(void) const { return mFactory; }
	inline const Vendor* GetVendor(void) const { return mVendor; }

public:
	inline size_t GetQueueCount(void) const { return mQueues.size(); }
	inline Queue* GetQueue(size_t index) const { return mQueues.at(index); }

protected:
	Vendor* mVendor = nullptr;
	Factory* mFactory = nullptr;

protected:
	std::vector<Queue*> mQueues;
};

Device* CreateDevice(void);
void DestroyDevice(Device* device);

} /* namespace Render */

#endif /* SOURCE_CORE_RENDER_RENDERDEVICE_H_ */
