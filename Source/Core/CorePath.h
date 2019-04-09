/*
 * CorePath.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREPATH_H_
#define SOURCE_CORE_COREPATH_H_

#include "CoreInterface.h"
#include <vector>

namespace Core
{
class Pass;
class Path : public Interface
{
public:
	explicit Path(System* system);
	virtual ~Path(void) override;

public:
	Pass* CreatePass(void);

public:
	inline size_t GetPassCount(void) const { return mPasses.size(); }
	inline Pass* GetRenderPass(size_t index) const { return mPasses.at(index); }

protected:
	std::vector<Pass*> mPasses;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPATH_H_ */
