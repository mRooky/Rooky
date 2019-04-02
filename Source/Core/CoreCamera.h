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
	inline void SetFov(float fov) { mFov = fov; }
	inline void SetFar(float far) { mFar = far; }
	inline void SetNear(float near) { mNear = near; }
	inline void SetType(CameraType type) { mType = type; }

public:
	inline float GetFov(void) const { return mFov; }
	inline float GetFar(void) const { return mFar; }
	inline float GetNear(void) const { return mNear; }
	inline CameraType GetType(void) const { return mType; }

public:
	inline Render::Matrix* GetMatrix(void) { return &mMatrix; }

protected:
	float mFov = 45.0f;
	float mFar = 100.0f;
	float mNear = 0.01f;
	Render::Matrix mMatrix = {};
	CameraType mType = CameraType::CAMERA_TYPE_PERSPECTIVE;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORECAMERA_H_ */
