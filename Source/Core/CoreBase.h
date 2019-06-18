/*
 * CoreBase.h
 *
 *  Created on: Apr 2, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_COREBASE_H_
#define SOURCE_CORE_COREBASE_H_

#include <string>

namespace Core
{

class Base
{
protected:
	Base(void);
	virtual ~Base(void);

public:
	inline void SetName(const char* name) { mName = name; }
	inline const char* GetName(void) const { return mName.c_str(); }

public:
	inline uint32_t GetID(void) const { return mID; }

protected:
	uint32_t mID = 0;
	std::string mName;
};

} /* namespace Core */

#endif /* SOURCE_CORE_COREBASE_H_ */
