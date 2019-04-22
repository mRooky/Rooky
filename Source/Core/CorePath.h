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
class SubPath;
class Path : public Interface
{
public:
	explicit Path(System* system);
	virtual ~Path(void) override;

public:
	SubPath* CreateSubPath(void);

public:
	inline size_t GetSubPathCount(void) const { return mSubPathes.size(); }
	inline SubPath* GetSubPath(size_t index) const { return mSubPathes.at(index); }

protected:
	std::vector<SubPath*> mSubPathes;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPATH_H_ */
