/*
 * CoreCamera.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORECAMERA_H_
#define SOURCE_CORE_CORECAMERA_H_

#include "RenderMatrix.hpp"

namespace Core
{

class Camera
{
public:
	Camera(void);
	virtual ~Camera(void);

protected:
	Render::Matrix mMatrix = {};
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORECAMERA_H_ */
