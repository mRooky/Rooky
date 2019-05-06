/*
 * CoreThread.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETHREAD_H_
#define SOURCE_CORE_CORETHREAD_H_

#include "GHIClasses.h"
#include "CoreInterface.h"
#include <vector>

namespace Core
{
class Thread : public Interface
{
public:
	explicit Thread(System* system);
	virtual ~Thread(void) override;

public:
	void Create(uint32_t count = 0);

public:
	GHI::CommandList* Allocate(bool primary);

public:
	inline size_t GetCommandListCount(void) const { return mCommandLists.size(); }
	inline GHI::CommandPool* GetCommandPool(void) const { return mCommandPool; }
	inline GHI::CommandList* GetCommandList(size_t index) const { return mCommandLists.at(index); }

protected:
	GHI::CommandPool* mCommandPool = nullptr;

public:
	std::vector<GHI::CommandList*> mCommandLists;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETHREAD_H_ */
