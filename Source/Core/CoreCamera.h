/*
 * CoreCamera.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORECAMERA_H_
#define SOURCE_CORE_CORECAMERA_H_

#include "CoreBase.h"
#include "CoreCameraData.h"
#include "Math/MathFrustum.h"
#include <vector>

namespace Core
{
class Uniform;
enum class CameraType : uint32_t
{
	CAMERA_TYPE_PERSPECTIVE,
	CAMERA_TYPE_ORTHOGRAPHIC,
	CAMERA_TYPE_UNKNOWN = ~0u
};

class Camera : public Base
{
public:
	Camera(void);
	virtual ~Camera(void) override;

public:
	void UpdateUniform(void);

public:
	inline void SetType(CameraType type) { mType = type; }
	inline CameraType GetType(void) const { return mType; }

public:
	inline void SetUniform(Uniform* uniform) { mUniform = uniform; }
	inline Uniform* GetUniform(void) const { return mUniform; }

public:
	inline const Math::Frustum& GetFrustum(void) const { return mFrustum; }

protected:
	CameraData mCameraData = {};
	Uniform* mUniform = nullptr;

protected:
	Math::Frustum mFrustum = {};
	CameraType mType = CameraType::CAMERA_TYPE_PERSPECTIVE;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORECAMERA_H_ */
