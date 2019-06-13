/*
 * KernelGuid.h
 *
 *  Created on: May 10, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELGUID_H_
#define SOURCE_CORE_KERNEL_KERNELGUID_H_

#include "KernelString.h"
#include "../Number/NumberUint.h"

namespace Kernel
{

class Guid
{
public:
	Guid(void) { Generate(); }
	~Guid(void) = default;

public:
	Guid(const Guid& other) : mCode(other.mCode) {}

public:
	String GetString(void) const;

public:
	inline Guid& operator=(const Guid& other)
	{
		mCode = other.mCode;
		return *this;
	}

public:
	inline bool operator==(const Guid& other) const
	{
		return (mCode == other.mCode);
	}

private:
	void Generate(void);

private:
	Number::Uint128 mCode = {};
};

} /* namespace Kernel */

#endif /* SOURCE_CORE_KERNEL_KERNELGUID_H_ */
