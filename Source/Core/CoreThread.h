/*
 * CoreThread.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETHREAD_H_
#define SOURCE_CORE_CORETHREAD_H_

#include "RenderClasses.h"
#include <vector>

namespace Core
{

class Thread
{
public:
	Thread(void);
	virtual ~Thread(void);

public:
	virtual Render::CommandList* Allocate(bool level) = 0;

public:
	inline Render::CommandPool* GetCommandPool(void) const { return mCommandPool; }
	inline Render::CommandList* GetCommandList(size_t index) const { return mCommandLists.at(index); }

protected:
	Render::CommandPool* mCommandPool = nullptr;
	std::vector<Render::CommandList*> mCommandLists;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETHREAD_H_ */
