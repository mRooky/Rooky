/*
 * CoreScene.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESCENE_H_
#define SOURCE_CORE_CORESCENE_H_

#include <vector>

namespace Core
{
class System;
class Viewport;
class Scene
{
public:
	Scene(void);
	virtual ~Scene(void);

public:
	inline System* GetSystem(void) const { return mSystem; }

protected:
	System* mSystem = nullptr;
	std::vector<Viewport*> mViewports;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESCENE_H_ */
