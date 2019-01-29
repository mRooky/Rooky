/*
 * CoreMemory.h
 *
 *  Created on: Jan 23, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREMEMORY_H_
#define SOURCE_CORE_COREMEMORY_H_

#include "RenderClasses.h"

namespace Core
{

class Memory
{
public:
	Memory(void);
	virtual ~Memory(void);

public:
	Render::Memory* GetMemory(void) const { return m_memory; }

private:
	Render::Memory* m_memory = nullptr;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREMEMORY_H_ */
