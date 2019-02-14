/*
 * CoreThread.h
 *
 *  Created on: Jan 30, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_CORETHREAD_H_
#define SOURCE_CORE_CORETHREAD_H_

#include "CoreObject.h"

#include "RenderClasses.h"
#include <vector>

namespace Core
{

class Thread : public Object
{
public:
	explicit Thread(System* system);
	virtual ~Thread(void) override;

public:
	void Create(void);

public:
	Render::CommandList* Allocate(bool primary);

public:
	inline size_t GetCommandListCount(void) const { return mCommandLists.size(); }
	inline Render::CommandPool* GetCommandPool(void) const { return mCommandPool; }
	inline Render::CommandList* GetCommandList(size_t index) const { return mCommandLists.at(index); }

protected:
	Render::CommandPool* mCommandPool = nullptr;
	std::vector<Render::CommandList*> mCommandLists;
};

} /* namespace Core */

#endif /* SOURCE_CORE_CORETHREAD_H_ */
