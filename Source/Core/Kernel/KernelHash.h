/*
 * KernelCompile.h
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELCOMPILE_H_
#define SOURCE_CORE_KERNEL_KERNELCOMPILE_H_

#include <cstdint>
#include <cstddef>

namespace Kernel
{
class Hash
{
public:
	Hash(void) = default;
	~Hash(void) = default;

public:
	Hash(size_t code) :
		mCode(code)
	{
	}

	Hash(const Hash& other) :
		mCode(other.mCode)
	{
	}

public:
	inline operator size_t(void) const
	{
		return mCode;
	}

public:
	inline Hash& operator=(size_t code)
	{
		mCode = code;
		return *this;
	}

	inline Hash& operator=(const Hash& other)
	{
		mCode = other.mCode;
		return *this;
	}

public:
	inline bool operator==(const Hash& other) const
	{
		return mCode == other.mCode;
	}

public:
	inline size_t GetCode(void) const
	{
		return mCode;
	}

protected:
	size_t mCode = 0;
};

}

#endif /* SOURCE_CORE_KERNEL_KERNELCOMPILE_H_ */
