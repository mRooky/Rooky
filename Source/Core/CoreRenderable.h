/*
 * CoreRenderable.h
 *
 *  Created on: Apr 4, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORERENDERABLE_H_
#define SOURCE_CORE_CORERENDERABLE_H_

#include "MathFrustum.h"
#include "CoreBase.h"

namespace Core
{
class Material;
class Renderable : public Base
{
public:
	Renderable(void);
	virtual ~Renderable(void) override;

public:
	virtual bool IsVisible(const Math::Frustum& frustum) = 0;

public:
	inline Material* GetMaterial(void) const { return mMaterial; }
	inline void SetMaterial(Material* material) { mMaterial = material; }

protected:
	Material* mMaterial = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORERENDERABLE_H_ */
