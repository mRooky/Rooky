/*
 * CorePath.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREPATH_H_
#define SOURCE_CORE_COREPATH_H_

#include "CoreObject.h"

#include <vector>

namespace Core
{
class Pass;
class Path : public Object
{
public:
	explicit Path(System* system);
	virtual ~Path(void);

public:
	Pass* CreatePass(void);

public:
	inline size_t GetPassCount(void) const { return mPasses.size(); }
	inline Pass* GetPass(size_t index) const { return mPasses.at(index); }

protected:
	std::vector<Pass*> mPasses;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPATH_H_ */
