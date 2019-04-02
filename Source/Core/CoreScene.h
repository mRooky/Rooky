/*
 * CoreScene.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORESCENE_H_
#define SOURCE_CORE_CORESCENE_H_

namespace Core
{
class System;
class Scene
{
public:
	Scene(void);
	virtual ~Scene(void);

public:
	inline System* GetSystem(void) const { return mSystem; }

protected:
	System* mSystem = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORESCENE_H_ */
