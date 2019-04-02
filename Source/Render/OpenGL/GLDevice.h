/*
 * Device.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_RENDER_OPENGL_GLDEVICE_H_
#define SOURCE_RENDER_OPENGL_GLDEVICE_H_

#include "RenderDevice.h"

namespace GL
{

class Device : public Render::Device
{
public:
	Device(void);
	virtual ~Device(void) override;
};

} /* namespace GL */

#endif /* SOURCE_RENDER_OPENGL_GLDEVICE_H_ */
