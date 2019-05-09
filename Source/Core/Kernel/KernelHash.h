/*
 * KernelCompile.h
 *
 *  Created on: Apr 16, 2019
 *      Author: rookyma
 */

#ifndef SOURCE_CORE_KERNEL_KERNELCOMPILE_H_
#define SOURCE_CORE_KERNEL_KERNELCOMPILE_H_

#include <functional>

namespace Kernel
{
class Hash
{
public:
	Hash(void) = default;
	~Hash(void) = default;

public:
	inline operator size_t(void) const { return mCode; }

public:
	template<typename T>
	inline void CalcHash(const T& source)
	{
		mCode = std::hash<T>()(source);
	}

public:
	inline bool operator==(const Hash& other) const
	{
		return mCode == other.mCode;
	}

public:
	inline size_t GetCode(void) const { return mCode; }

protected:
	size_t mCode = 0;
};

}

#endif /* SOURCE_CORE_KERNEL_KERNELCOMPILE_H_ */
