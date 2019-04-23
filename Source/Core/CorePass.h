/*
 * CorePath.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREPASS_H_
#define SOURCE_CORE_COREPASS_H_

#include "CoreInterface.h"
#include <vector>

namespace Core
{
class SubPass;
class Pass : public Interface
{
public:
	explicit Pass(System* system);
	virtual ~Pass(void) override;

public:
	SubPass* CreateSubPass(void);

public:
	inline size_t GetSubPassCount(void) const { return mSubPasses.size(); }
	inline SubPass* GetSubPass(size_t index) const { return mSubPasses.at(index); }

protected:
	std::vector<SubPass*> mSubPasses;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREPASS_H_ */
