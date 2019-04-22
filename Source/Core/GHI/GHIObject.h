/*
 * RenderObject.h
 *
 *  Created on: Jan 21, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_GHI_RENDEROBJECT_H_
#define SOURCE_CORE_GHI_RENDEROBJECT_H_

namespace GHI
{
class Device;
class Object
{
protected:
	explicit Object(Device* device);

public:
	virtual ~Object(void);

public:
	inline Device* GetDevice(void) const { return mDevice; }

public:
	virtual inline void Destroy(void) { delete this; }

protected:
	Device* mDevice = nullptr;
};

} /* namespace Render */

#endif /* SOURCE_CORE_GHI_RENDEROBJECT_H_ */
