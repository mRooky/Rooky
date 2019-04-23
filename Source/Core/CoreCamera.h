/*
 * CoreCamera.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORECAMERA_H_
#define SOURCE_CORE_CORECAMERA_H_

#include "MathFrustum.h"

namespace Core
{
enum class CameraType : uint32_t
{
	CAMERA_TYPE_PERSPECTIVE,
	CAMERA_TYPE_ORTHOGRAPHIC,
	CAMERA_TYPE_UNKNOWN = ~0u
};

class Camera
{
public:
	Camera(void);
	virtual ~Camera(void);

public:
	inline void SetType(CameraType type) { mType = type; }
	inline CameraType GetType(void) const { return mType; }

public:
	inline Math::Frustum* GetFrustum(void) { return &mFrustum; }

protected:
	Math::Frustum mFrustum = {};
	CameraType mType = CameraType::CAMERA_TYPE_PERSPECTIVE;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORECAMERA_H_ */
